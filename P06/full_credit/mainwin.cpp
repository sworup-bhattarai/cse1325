#include "mainwin.h"
#include <iostream> // for std::cerr logging

Mainwin::Mainwin() : nim{nullptr} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("The Game of Nim");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   G A M E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     	I N S E R T
    // Create a Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //           N E W  S T U D E N T
    // Append Rules to the Insert menu
    Gtk::MenuItem *menuitem_rules = Gtk::manage(new Gtk::MenuItem("_New Student", true));
    menuitem_rules->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_rules);

    //           N E W  P A R E N T 
    // Append About to the Insert menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_New Parent", true));
    menuitem_about->signal_activate().connect([this] {this->on_new_parents_clicked();});
    insertmenu->append(*menuitem_about);
    
    //     	R E L A T E 
    // Create a Relate menu and add to the menu bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    //           S T U D E N T  T O  P A R E N T 
    // Append Rules to the Insert menu
    Gtk::MenuItem *menuitem_stp = Gtk::manage(new Gtk::MenuItem("_Student to parent", true));
    menuitem_stp->signal_activate().connect([this] {this->on_student_to_parent_click();});
    relatemenu->append(*menuitem_stp);    
    

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);

    // /////////////////////////// ////////////////////////////////////////////
    // S T I C K S   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
    on_new_school_click();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

// COMBINED observer / callback
void Mainwin::on_button_click(int button) {
    try {
        // Catch the "impossible" out of sticks exception
        nim->take_sticks(button);
        set_sticks();
    } catch(std::exception& e) {
        sticks->set_markup("<b>FAIL:</b> " + std::string{e.what()} + ", start new game");
    }
}

void Mainwin::on_computer_player_click() {
    set_sticks();
}

void Mainwin::on_new_school_click() {
    delete nim;
    nim = new Nim();
    set_sticks();
}

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_rules_click() {
    Glib::ustring s = R"(
<span size='24000' weight='bold'>The Rules of Nim</span>
<span size='large'>Copyright 2017-2020 by George F. Rice - CC BY 4.0</span>

The two players alternate taking 1 to 3 sticks from the pile. The goal is to force your opponent to take the last stick (called misère rules).

If the computer button is up, it's a two player game. If down, the computer is always Player 2.)";
    Gtk::MessageDialog{*this, s, true}.run(); // 'true' as 3rd parameter enables Pango markup
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("Nim");
    auto logo = Gdk::Pixbuf::create_from_file("128px-Pyramidal_matches.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.2.1");
    dialog.set_copyright("Copyright 2017-2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"George F. Rice"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logo by M0tty, licensed under CC BY-SA 3.0 https://commons.wikimedia.org/wiki/File:Pyramidal_matches.svg",
        "Robot by FreePik.com, licensed for personal and commercial purposes with attribution https://www.freepik.com/free-vector/grey-robot-silhouettes_714902.htm"};
    dialog.set_artists(artists);
    dialog.run();
}

// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::set_sticks() {
    // s collects the status message
    Glib::ustring s = "";

    // If the robot is enabled and it's their turn, move the robot
    if (nim->sticks_left() > 0) {
        if (computer_player->get_active() && nim->current_player() == 2) {
           int move = 1;
           try {
               move = nim->optimal_move();      // "Impossible" exception warning
           } catch(std::exception& e) {         // If it happens, log an error
               std::cerr << "Invalid optimal move: " << e.what() << std::endl;
           }
           s += "Robot plays " + std::to_string(move) + ", ";
           nim->take_sticks(move); 
        }
    }

    // Report who's turn it is, or (if all sticks gone) who won
    if (nim->sticks_left() > 0) {
        s += "Player " + std::to_string(nim->current_player()) + "'s turn";
    } else {
        s += "<span size='16000' weight='bold'>Player " 
              +  std::to_string(3-nim->current_player()) 
              +  " wins!</span>";
    }

    // Display the collected status on the status bar
    msg->set_markup(s);

    // Update the visual display of sticks
    s = "<span size='24000' weight='bold'>";
    for(int i=0; i<nim->sticks_left(); ++i) s.append("| ");
    s.append("</span>  (" + std::to_string(nim->sticks_left()) + " sticks)");
    sticks->set_markup(s);

    // Set sensitivity of the human stick selectors so user can't make an illegal move
    button1->set_sensitive(nim->sticks_left() > 0);
    button2->set_sensitive(nim->sticks_left() > 1);
    button3->set_sensitive(nim->sticks_left() > 2);
}

