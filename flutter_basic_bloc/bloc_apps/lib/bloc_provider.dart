import 'package:bloc_apps/bloc/counter.dart';
import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';

class BlocProviderScreen extends StatelessWidget {
  const BlocProviderScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    Counter myCounter = BlocProvider.of<Counter>(context);
    return Scaffold(
      appBar: AppBar(
        title: const Text('06 Bloc Provider'),
      ),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Material(
                color: Colors.blue,
                child: InkWell(
                  onTap: () {
                    myCounter.decrement();
                  },
                  child: Container(
                    padding: const EdgeInsets.all(10.0),
                    child: const Icon(
                      Icons.remove,
                      color: Colors.white,
                    ),
                  ),
                ),
              ),
              Material(
                color: Colors.green,
                child: Container(
                  padding: const EdgeInsets.all(10),
                  child: const CenterWidget(),
                ),
              ),
              Material(
                color: Colors.blue,
                child: InkWell(
                  onTap: () {
                    myCounter.increment();
                  },
                  child: Container(
                    padding: const EdgeInsets.all(10.0),
                    child: const Icon(
                      Icons.add,
                      color: Colors.white,
                    ),
                  ),
                ),
              ),
            ],
          ),
        ],
      ),
    );
  }
}

class CenterWidget extends StatelessWidget {
  const CenterWidget({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    Counter myCounter = BlocProvider.of<Counter>(context);
    return Center(
      child: BlocBuilder(
        bloc: myCounter,
        builder: (context, state) {
          return Text(
            '$state',
            style: const TextStyle(fontSize: 50, color: Colors.white),
          );
        },
      ),
    );
  }
}
