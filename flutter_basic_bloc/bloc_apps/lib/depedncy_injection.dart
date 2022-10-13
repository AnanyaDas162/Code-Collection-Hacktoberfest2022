import 'package:bloc_apps/bloc_provider_value.dart';
import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'bloc/counter.dart';

class DepedencyInjectionScreen extends StatelessWidget {
  const DepedencyInjectionScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    Counter myCounter = BlocProvider.of<Counter>(context);
    return Scaffold(
      appBar: AppBar(
        title: const Text('07 Depedency Injection'),
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
                    height: 50,
                    width: 100,
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
                    height: 50,
                    width: 100,
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
      floatingActionButton: FloatingActionButton(
        child: const Icon(Icons.arrow_forward),
        onPressed: () {
          Navigator.of(context).push(
            MaterialPageRoute(
              // Parsing bloc class to other page
              builder: (context) => BlocProvider.value(
                value: myCounter,
                child: const BlocProviderValueScreen(),
              ),
            ),
          );
        },
      ),
    );
  }
}

class CenterWidget extends StatelessWidget {
  const CenterWidget({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return const Center(
      child: RedWidget(),
    );
  }
}

class RedWidget extends StatelessWidget {
  const RedWidget({
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      color: Colors.red,
      child: const YellowWidget(),
    );
  }
}

class YellowWidget extends StatelessWidget {
  const YellowWidget({
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      color: Colors.yellow,
      margin: const EdgeInsets.all(10),
      child: const BlueWidget(),
    );
  }
}

class BlueWidget extends StatelessWidget {
  const BlueWidget({
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.all(10),
      color: Colors.blue,
      height: 50,
      width: 50,
      child: const DataWidget(),
    );
  }
}

class DataWidget extends StatelessWidget {
  const DataWidget({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    //Counter myCounter = BlocProvider.of<Counter>(context);
    Counter myCounter = context.read<Counter>();
    return BlocBuilder(
      bloc: myCounter,
      builder: (context, state) {
        return Center(
          child: Text(
            '$state',
            style: const TextStyle(fontSize: 30, color: Colors.white),
          ),
        );
      },
    );
  }
}
