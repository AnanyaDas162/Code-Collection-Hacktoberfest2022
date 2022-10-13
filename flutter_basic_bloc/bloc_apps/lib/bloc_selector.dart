import 'package:bloc_apps/bloc/user.dart';
import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';

class BlocSelectorScreen extends StatelessWidget {
  const BlocSelectorScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    UserBloc user = context.read<UserBloc>();
    return Scaffold(
      appBar: AppBar(
        title: const Text('08 Bloc Selector'),
      ),
      body: ListView(
        padding: const EdgeInsets.all(15.0),
        children: [
          BlocSelector<UserBloc, Map<String, dynamic>, String>(
            selector: (state) => state['name'],
            builder: (context, state) {
              return Text('Nama : $state');
            },
          ),
          BlocSelector<UserBloc, Map<String, dynamic>, int>(
            selector: (state) => state['age'],
            builder: (context, state) {
              return Text('Umur : $state');
            },
          ),
          const SizedBox(height: 20.0),
          TextField(
            onChanged: (value) => user.changeName(value),
            decoration: const InputDecoration(border: OutlineInputBorder()),
          ),
          const SizedBox(height: 20.0),
          Row(
            children: [
              IconButton(
                onPressed: () {
                  user.changeAge(user.state['age'] - 1);
                },
                icon: const Icon(Icons.remove),
              ),
              IconButton(
                onPressed: () {
                  user.changeAge(user.state['age'] + 1);
                },
                icon: const Icon(Icons.add),
              ),
            ],
          ),
        ],
      ),
    );
  }
}
