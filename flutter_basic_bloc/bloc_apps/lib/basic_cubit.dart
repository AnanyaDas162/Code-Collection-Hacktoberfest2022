import 'package:bloc/bloc.dart';
import 'package:flutter/material.dart';

class CounterCubit extends Cubit<int> {
  CounterCubit({this.initialData = 0}) : super(initialData);

  int initialData;

  void increment() {
    emit(state + 1);
  }

  void decrement() {
    emit(state - 1);
  }

  // Observer
  @override
  void onChange(Change<int> change) {
    super.onChange(change);
    print(change);
  }

  @override
  void onError(Object error, StackTrace stackTrace) {
    super.onError(error, stackTrace);
    print(error);
  }
}

// ignore: must_be_immutable
class BasicCubitScreen extends StatelessWidget {
  BasicCubitScreen({Key? key}) : super(key: key);

  CounterCubit myCounter = CounterCubit(initialData: 20);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('02 Basic Cubit'),
      ),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          StreamBuilder(
              initialData: myCounter.initialData,
              stream: myCounter.stream,
              builder: (context, snaphoot) {
                return Text(
                  '${snaphoot.data}',
                  style: const TextStyle(fontSize: 50),
                );
              }),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              IconButton(
                onPressed: () {
                  myCounter.decrement();
                },
                icon: const Icon(Icons.remove),
              ),
              IconButton(
                onPressed: () {
                  myCounter.increment();
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
