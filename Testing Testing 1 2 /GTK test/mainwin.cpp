#include "mainwin.h"
#include <iostream>

Mainwin::Mainwin() : button{new Gtk::Button{"Hello there. \nGeneral Knobi...."}} {
  add(*button);
  button->signal_clicked().connect([this] {this->on_button_click();});
  button->show();
}

Mainwin::~Mainwin() { }

void Mainwin::on_button_click() {
    std::cout << "Hello, world!" << std::endl;
}
