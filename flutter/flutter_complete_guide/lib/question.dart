import 'package:flutter/material.dart';

class Question extends StatelessWidget {
  String questionText;
  // ignore: use_key_in_widget_constructors
  Question(this.questionText);

  @override
  Widget build(BuildContext context) {
    return Container(
      width: double.infinity,
      margin: EdgeInsets.all(10),
      child: Text(
        questionText,
        textAlign: TextAlign.center,
        style: TextStyle(fontSize: 28),
      ),
    );
  }
}
