import 'package:bloc_apps/basic_cubit.dart';
import 'package:bloc_apps/bloc/theme.dart';
import 'package:bloc_apps/bloc/user.dart';
import 'package:bloc_apps/bloc_builder.dart';
import 'package:bloc_apps/bloc_consumer.dart';
import 'package:bloc_apps/bloc_listener.dart';
import 'package:bloc_apps/bloc_provider.dart';
import 'package:bloc_apps/bloc_selector.dart';
import 'package:bloc_apps/depedncy_injection.dart';
import 'package:bloc_apps/extension_method.dart';
import 'package:bloc_apps/stream.dart';
import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';

import 'bloc/counter.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final ThemeApp appTheme = ThemeApp();
    return MultiBlocProvider(
        providers: [
          BlocProvider(create: (context) => Counter()),
          BlocProvider(create: (context) => UserBloc()),
          BlocProvider(create: (context) => appTheme),
        ],
        child: BlocBuilder<ThemeApp, bool>(
          bloc: appTheme,
          builder: (context, state) {
            return MaterialApp(
              title: 'Flutter Demo',
              theme: state == false ? ThemeData.light() : ThemeData.dark(),
              home: const HomePage(),
            );
          },
        ));
    // Bloc Provider Materi 06
    // return BlocProvider(
    //   create: (context) => Counter(),
    //   child: MaterialApp(
    //     title: 'Flutter Demo',
    //     theme: ThemeData(
    //       primarySwatch: Colors.blue,
    //     ),
    //     home: const HomePage(),
    //   ),
    // );
  }
}

class HomePage extends StatelessWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    ThemeApp themeApp = context.read<ThemeApp>();
    return BlocBuilder<ThemeApp, bool>(
      bloc: themeApp,
      builder: (context, state) {
        return Scaffold(
          appBar: AppBar(
            title: const Text('Flutter Bloc Begginer'),
          ),
          body: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 20),
            child: ListView(
              children: [
                ItemMenu(
                  title: '01 Stream',
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => const StreamScreen(),
                      ),
                    );
                  },
                ),
                ItemMenu(
                  title: '02 Basic Cubit',
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => BasicCubitScreen(),
                      ),
                    );
                  },
                ),
                ItemMenu(
                  title: '03 Bloc Builder',
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => BlocBuilderScreen(),
                      ),
                    );
                  },
                ),
                ItemMenu(
                  title: '04 Bloc Listener',
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => BlocListenerScreen(),
                      ),
                    );
                  },
                ),
                ItemMenu(
                  title: '05 Bloc Consumer',
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => BlocConsumerScreen(),
                      ),
                    );
                  },
                ),
                ItemMenu(
                  title: '06 Bloc Provider',
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => const BlocProviderScreen(),
                      ),
                    );
                  },
                ),
                ItemMenu(
                  title: '07 Depedency Injection',
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => const DepedencyInjectionScreen(),
                      ),
                    );
                  },
                ),
                ItemMenu(
                  title: '08 Bloc Selector',
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => const BlocSelectorScreen(),
                      ),
                    );
                  },
                ),
                ItemMenu(
                  title: '09 Extension Method',
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => ExtensionMethodScreen(),
                      ),
                    );
                  },
                ),
              ],
            ),
          ),
          floatingActionButton: FloatingActionButton(
            child: Icon(
              state == true ? Icons.wb_sunny : Icons.brightness_2,
            ),
            onPressed: () {
              themeApp.changeTheme();
            },
          ),
        );
      },
    );
  }
}

class ItemMenu extends StatelessWidget {
  final String title;
  final VoidCallback onTap;
  final bool isDark;
  const ItemMenu(
      {Key? key, required this.title, required this.onTap, this.isDark = false})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    ThemeApp themeApp = context.read<ThemeApp>();
    return BlocBuilder<ThemeApp, bool>(
      bloc: themeApp,
      builder: (context, state) {
        return InkWell(
          onTap: () {
            onTap();
          },
          child: Container(
            decoration: BoxDecoration(
              color: state ? Colors.black87 : Colors.white,
              borderRadius: const BorderRadius.all(Radius.circular(3.0)),
              boxShadow: [
                BoxShadow(
                  color: state ? Colors.transparent : Colors.black26,
                  offset: const Offset(0, 1),
                  blurRadius: 2.0,
                )
              ],
            ),
            child: ListTile(
              title: Text(
                title,
                style: TextStyle(color: state ? Colors.white : Colors.black),
              ),
              trailing: Icon(
                Icons.arrow_forward_ios,
                size: 15,
                color: state ? Colors.white : Colors.black,
              ),
            ),
          ),
        );
      },
    );
  }
}
