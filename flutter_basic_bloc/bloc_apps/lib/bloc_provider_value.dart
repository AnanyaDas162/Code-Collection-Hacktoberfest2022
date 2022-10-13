import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'bloc/counter.dart';

class BlocProviderValueScreen extends StatelessWidget {
  const BlocProviderValueScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    Counter myCounter = context.read<Counter>();
    return Scaffold(
      appBar: AppBar(
        title: const Text('Bloc Provider Value'),
      ),
      body: Center(
        child: BlocBuilder(
          bloc: myCounter,
          builder: (context, state) {
            return Text(
              '$state',
              style: const TextStyle(fontSize: 30),
            );
          },
        ),
      ),
    );
  }
}
