#include "mainwin.h"
#include <iostream> // for std::cerr logging

Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(600, 200);
    set_title("School Management And Reporting Tool(S.M.A.R.T.)");

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
    Gtk::MenuItem *menuitem_rules = Gtk::manage(new Gtk::MenuItem("New _Student", true));
    menuitem_rules->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_rules);

    //           N E W  P A R E N T 
    // Append About to the Insert menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("New _Parent", true));
    menuitem_about->signal_activate().connect([this] {this->on_new_parents_click();});
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




void Mainwin::on_new_school_click() {
    
    student.clear();
    parent.clear();
}

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_new_student_click(){
	
}       
void Mainwin::on_new_parents_click(){
	
}   
void Mainwin::on_student_to_parent_click(){
	
}

