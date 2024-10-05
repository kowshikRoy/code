/* This is a basic example of creating a C++ stream from a file
 * descriptor and how to read/write from/to it
 *
 * Needs GCC's libstdc++ and a POSIX environment
 *
 * Author: Diego Barrios Romero
 * Public domain Copyleft 2011
 */

#ifndef _FDSTREAM_
#define _FDSTREAM_

#include <iostream>
#include <unistd.h>

#define BUFFER_SIZE (512)

class _fdstream
{
protected:
  _fdstream()
    : _filebuf(NULL), _file_descriptor(-1)
  { }

  _fdstream(int file_descriptor, std::ios_base::openmode openmode)
    : _filebuf(NULL), _file_descriptor(file_descriptor), _openmode(openmode)
  {
    open(file_descriptor, openmode);
  }

  std::ios_base::openmode openmode() const { return _openmode; }

  void open(int file_descriptor, std::ios_base::openmode openmode)
  {
    if (!_filebuf)
      // We create a C++ stream from a file descriptor
      // stdio_filebuf is not synced with stdio.
      // From GCC 3.4.0 on exists in addition stdio_sync_filebuf
      // You can also create the filebuf from a FILE* with
      // FILE* f = fdopen(file_descriptor, mode);
      _filebuf = new __gnu_cxx::stdio_filebuf<char> (file_descriptor,
                                                     openmode);
  }

  virtual ~_fdstream()
  {
    close(_file_descriptor);
    delete _filebuf;
  }

  __gnu_cxx::stdio_filebuf<char>* _filebuf;
private:
  int _file_descriptor;
  std::ios_base::openmode _openmode;
};

class ifdstream : public _fdstream
{
public:
  ifdstream() :
      _fdstream(), _stream(NULL)
  { }

  ifdstream(int file_descriptor) :
      _fdstream(file_descriptor, std::ios_base::in)
  {
    _stream = new std::istream (_filebuf);
  }

  void open(int file_descriptor)
  {
    if (!_stream)
    {
      _fdstream::open(file_descriptor, std::ios_base::in);
      _stream = new std::istream (_filebuf);
    }
  }

  ifdstream& operator>> (std::string& str)
  {
    (*_stream) >> str;

    return *this;
  }

  size_t getline (char* s, std::streamsize n)
  {
    return (getline(s, n, '\n'));
  }

  size_t getline (char* s, std::streamsize n, char delim)
  {
    int i = 0;
    do
    {
      s[i] = _stream->get();
      i++;
    } while(i < n-1 && s[i-1] != delim && s[i-1] != '\0');

    s[i-1] = '\0'; // overwrite the delimiter given with std::string end

    return i-1;
  }

  ~ifdstream()
  {
    delete _stream;
  }

private:
  std::istream* _stream;
};

class ofdstream : public _fdstream
{
public:
  ofdstream()
    : _fdstream(), _stream(NULL)
  { }

  ofdstream(int file_descriptor)
    : _fdstream(file_descriptor, std::ios_base::out)
  {
    _stream = new std::ostream (_filebuf);
  }

  void open(int file_descriptor)
  {
    if (!_stream)
    {
      _fdstream::open(file_descriptor, std::ios_base::out);
      _stream = new std::ostream (_filebuf);
    }
  }


  ofdstream& operator<< (const std::string& str)
  {
    if (_stream->good())
    {
      (*_stream) << str;
    }

    _stream->flush();
    return *this;
  }

  ~ofdstream()
  {
    delete _stream;
  }

private:
  std::ostream* _stream;
};

size_t getline (ifdstream& ifds, std::string& str)
{
  char tmp[BUFFER_SIZE];
  size_t ret = ifds.getline(tmp, BUFFER_SIZE);
  str = tmp;
  return ret;
}

#else
# error "Not supported"
#endif

#endif // _FDSTREAM_