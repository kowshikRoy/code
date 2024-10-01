import 'package:flutter/material.dart';

import './question.dart';
void main() => runApp(MyApp());

class MyApp extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    return MyAppState();
  }
}
class MyAppState extends State<MyApp> {
  var qid = 0;
  var questions = [
    'What\'s your favorite color',
    'What\'s your favorite animal'
  ];
  void answerQuestion() {
    setState(() {
      qid += 1;
    });
    print(qid);
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text("My First App"),
        ),
        body: Column(
          children: [
            Question(questions[qid]),
            ElevatedButton(onPressed: answerQuestion, child: Text("Answer 1")),
            ElevatedButton(onPressed: answerQuestion, child: Text("Answer 2")),
            ElevatedButton(onPressed: answerQuestion, child: Text("Answer 3")),
          ],
        ),
      ),
    );
  }
}