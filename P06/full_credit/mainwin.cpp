#include "mainwin.h"
#include "entrydialog.h"
#include <iostream> // for std::cerr logging

Mainwin::Mainwin() {
    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(550, 250);
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
    // P E O P L E   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    display = Gtk::manage(new Gtk::Label());
	
	show_data();
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
    show_data();
 
}

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_new_student_click(){
 
   	Gtk::Dialog dialog{"Student's info", *this};
    Gtk::Grid grid;
    
    Gtk::Label lname{"Name"};
    Gtk::Entry ename;               

    grid.attach(lname, 0, 1, 1, 1);
    grid.attach(ename, 1, 2, 2, 1);

    
    Gtk::Label lemail{"Email"};
    Gtk::Entry eemail;               

    grid.attach(lemail, 0, 3, 1, 1);
    grid.attach(eemail, 1, 4, 2, 1);

    Gtk::Label lgrade{"Grade"};
    Gtk::SpinButton sgrade;
    sgrade.set_range(1,12);
    sgrade.set_increments(1,5);       
    sgrade.set_value(10);              

    grid.attach(lgrade, 0, 5, 1, 1);
    grid.attach(sgrade, 1, 6, 2, 1);

   
    dialog.get_content_area()->add(grid);

    dialog.add_button("Ok", Gtk::RESPONSE_CANCEL);
    int response;

    dialog.show_all();

    while((response = dialog.run()) == Gtk::RESPONSE_OK) {}
	//waits till the cancle button disquized as an OK button is selected
	
	
	if (ename.get_text().size() != 0) {
    	if (eemail.get_text().size() != 0) {
    	
			student.push_back(Student{ename.get_text(),eemail.get_text(), sgrade.get_value_as_int()});	
		
        }
	}
	
	show_data();
			



}       
void Mainwin::on_new_parents_click(){
	
	Gtk::Dialog dialog{"Parent's info", *this};
    Gtk::Grid grid;
    
    Gtk::Label lname{"Name"};
    Gtk::Entry ename;               

    grid.attach(lname, 0, 1, 1, 1);
    grid.attach(ename, 1, 2, 2, 1);

    
    Gtk::Label lemail{"Email"};
    Gtk::Entry eemail;               

    grid.attach(lemail, 0, 3, 1, 1);
    grid.attach(eemail, 1, 4, 2, 1);

   
    dialog.get_content_area()->add(grid);

    dialog.add_button("Ok", Gtk::RESPONSE_CANCEL);
    int response;

    dialog.show_all();

    while((response = dialog.run()) == Gtk::RESPONSE_OK) {}
	//waits till the cancle button disquized as an OK button is selected
	
	
	if (ename.get_text().size() != 0) {
    	if (eemail.get_text().size() != 0) {
    	
			parent.push_back(Parent{ename.get_text(),eemail.get_text()});
        
        }
	}
	show_data();
			

	
}   
void Mainwin::on_student_to_parent_click(){
	Gtk::Dialog dialog{"Parents and Children", *this};
    Gtk::Grid grid;
    
    Gtk::Label d_par{"Pick a parent"};
    Gtk::ComboBoxText c_par{true}; 
	for (auto par : parent )
	{
		c_par.append(par.to_string());
	}
	c_par.set_active(0);
	
	grid.attach(d_par, 1, 0, 1, 1); 
    grid.attach(c_par, 1, 1, 2, 1);
    
    Gtk::Label d_stu{"Pick the parent's student"};
    Gtk::ComboBoxText c_stu{true}; 
	for (auto stu : student )
	{
		c_stu.append(stu.to_string());
	}
	c_stu.set_active(0);
	
	grid.attach(d_stu, 1, 2, 1, 1); 
    grid.attach(c_stu, 1, 3, 2, 1);

	dialog.get_content_area()->add(grid);

    dialog.add_button("Ok", Gtk::RESPONSE_CANCEL); 
    int response;

    dialog.show_all();

    while((response = dialog.run()) == Gtk::RESPONSE_OK) {}
    //waits till the cancle button disquized as an OK button is selected
    
    for (int i = 0 ; i < student.size(); i++ )
	{
		
		if (i == c_stu.get_active_row_number())
		{
			for (int j = 0 ; j < parent.size(); j++ )
			{
				
				if (i == c_par.get_active_row_number())
				{
					
					parent.at(j).add_student(student.at(i));
				
					student.at(i).add_parent(parent.at(j));
				
					break;
					
				}
			}
		}
	}
   	
   	
   	show_data();
}

void Mainwin::show_data() {

	/*std::string s = "Parents:\n";
	for (auto par : parent )
	{
		s += par.full_info();
	}
	s += "Students:\n";
	for (auto stu : student )
	{
		s+= stu.full_info();
	}*/
	
	Glib::ustring s = "";
	
	s = "Students:\n";
	 for (auto & st : student )
	{
		
		s = s + st.full_info() ;
		
	}
	s = s + "Parents:\n";
		
	for (auto & e : parent )
	{

		s = s + e.full_info() ;	
		
	}
    display->set_text(s);

}


