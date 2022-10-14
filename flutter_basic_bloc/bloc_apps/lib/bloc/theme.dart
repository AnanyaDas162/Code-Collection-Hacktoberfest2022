import 'package:bloc/bloc.dart';

class ThemeApp extends Cubit<bool> {
  ThemeApp() : super(false);

  void changeTheme() => emit(!state);
}
