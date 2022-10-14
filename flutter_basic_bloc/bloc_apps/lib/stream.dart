import 'package:flutter/material.dart';

class StreamScreen extends StatelessWidget {
  const StreamScreen({Key? key}) : super(key: key);

  Stream<int> countStream() async* {
    for (int i = 0; i <= 10; i++) {
      await Future.delayed(const Duration(seconds: 1));
      yield i;
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('01 Stream Builder')),
      body: StreamBuilder(
          stream: countStream(),
          builder: (context, snapshot) {
            if (snapshot.connectionState == ConnectionState.waiting) {
              return const Center(
                child: Text('Loading ...'),
              );
            } else {
              return Center(
                child: Text(
                  '${snapshot.data}',
                  style: const TextStyle(fontSize: 50),
                ),
              );
            }
          }),
    );
  }
}
