import 'package:bloc_apps/bloc/counter.dart';
import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';

class ExtensionMethodScreen extends StatelessWidget {
  const ExtensionMethodScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    // Counter myCounter = context.read<Counter>(); // Watch membaca state sekali
    // Counter myCounter =
    //     context.watch<Counter>(); // Watch membaca state berkali-kali
    return Scaffold(
      appBar: AppBar(
        title: const Text('09 Extension Method'),
      ),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Builder(builder: (context) {
            Counter myCounter = context.watch<Counter>();
            return Text(
              '${myCounter.state}',
              style: const TextStyle(fontSize: 50),
            );
          }),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              IconButton(
                onPressed: () {
                  context.read<Counter>().decrement();
                },
                icon: const Icon(Icons.remove),
              ),
              IconButton(
                onPressed: () {
                  context.read<Counter>().increment();
                },
                icon: const Icon(Icons.add),
              ),
            ],
          )
        ],
      ),
    );
  }
}
