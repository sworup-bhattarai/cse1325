#include "mainwin.h"
#include "entrydialog.h"
#include <iostream> // for std::cerr logging

const int MAX_STUDENTS = 100;
const int MAX_PARENTS = 400;


Mainwin::Mainwin() {
    // /////////////////
    // G U I   S E T U P
    // /////////////////
    
    student.reserve(MAX_STUDENTS);
	parent.reserve(MAX_PARENTS);
	sect.push_back("Reading");
	sect.push_back("Writing");
	sect.push_back("Math");
	sect.push_back("Science");
	sect.push_back("History");
	sect.push_back("Art");
	semester.push_back("Fall");
	semester.push_back("Spring");
	semester.push_back("Summer");
	
	
    set_default_size(550, 250);
    set_title("School Management And Reporting Tool(S.M.A.R.T.)");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // /////// ////////////////////////////////////////////////////////////////
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    
    //for the sub menu/ drop-down menu
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   G A M E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);
    
     //         S A V E   G A M E
    // Append Save... to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save ", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

     //         S A V E   G A M E
    // Append Save As... to the File menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);

    //         O P E N   G A M E
    // Append Open... to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);
   
   
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
    Gtk::MenuItem *menuitem_student = Gtk::manage(new Gtk::MenuItem("New _Student", true));
    menuitem_student->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_student);

    //           N E W  P A R E N T 
    // Append About to the Insert menu
    Gtk::MenuItem *menuitem_parent = Gtk::manage(new Gtk::MenuItem("New _Parent", true));
    menuitem_parent->signal_activate().connect([this] {this->on_new_parents_click();});
    insertmenu->append(*menuitem_parent);

    //           N E W  C O U R S E 
    // Append About to the Insert menu
    Gtk::MenuItem *menuitem_course = Gtk::manage(new Gtk::MenuItem("New _Course", true));
    menuitem_course->signal_activate().connect([this] {this->on_new_course();});
    insertmenu->append(*menuitem_course);
    
    //           N E W  S E C T I O N 
    // Append About to the Insert menu
    Gtk::MenuItem *menuitem_section = Gtk::manage(new Gtk::MenuItem("New _Section", true));
    menuitem_section->signal_activate().connect([this] {this->on_new_section();});
    insertmenu->append(*menuitem_section);
        
    //         T E S T   D A T A
    // Append Test Data to the Insert menu
    Gtk::MenuItem *menuitem_test_data = Gtk::manage(new Gtk::MenuItem("_Test Data", true));
    menuitem_test_data->signal_activate().connect([this] {this->on_easter_egg();});
    insertmenu->append(*menuitem_test_data);
    
    //     	R E L A T E 
    // Create a Relate menu and add to the menu bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    //           S T U D E N T  T O  P A R E N T 
    // Connects parents and students
    Gtk::MenuItem *menuitem_stp = Gtk::manage(new Gtk::MenuItem("_Student to parent", true));
    menuitem_stp->signal_activate().connect([this] {this->on_student_to_parent_click();});
    relatemenu->append(*menuitem_stp); 
    
    //     	V I E W 
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //           S T U D E N T  A N D  P A R E N T 
    // Shows parents and students
    Gtk::MenuItem *menuitem_sap = Gtk::manage(new Gtk::MenuItem("Student _and parent", true));
    menuitem_sap->signal_activate().connect([this] {this->show_data(1);});
    viewmenu->append(*menuitem_sap); 
    
    //           C O U R S E
    // Shows parents and students
    Gtk::MenuItem *menuitem_cou = Gtk::manage(new Gtk::MenuItem("_Courses", true));
    menuitem_cou->signal_activate().connect([this] {this->show_data(2);});
    viewmenu->append(*menuitem_cou); 
        
    //           S E C T I O N
    // Shows parents and students
    Gtk::MenuItem *menuitem_sec = Gtk::manage(new Gtk::MenuItem("_Sections", true));
    menuitem_sec->signal_activate().connect([this] {this->show_data(3);});
    viewmenu->append(*menuitem_sec); 
    
    
    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);  
    

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // ///////////// //////////////////////////////////////////////////////////
    
    
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);
    
    //     N E W   S C H O O L
    // Add a new school icon
    Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_school_button->set_tooltip_markup("Create a new school, discarding any in progress");
    new_school_button->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(*new_school_button);
    
    //     O P E N  S C H O O L
    // Add a open school icon
    Gtk::ToolButton *open_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    open_school_button->set_tooltip_markup("Open");
    open_school_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*open_school_button);
    
     //     S A V E  S C H O O L
    // Add a save school icon
    Gtk::ToolButton *save_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::FLOPPY));
    save_school_button->set_tooltip_markup("Save");
    save_school_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_school_button);
    
    //     S A V E  A S  S C H O O L
    // Add a save as school icon
    Gtk::ToolButton *save_as_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    save_as_school_button->set_tooltip_markup("Save As");
    save_as_school_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*save_as_school_button);
    
    Gtk::SeparatorToolItem *separator = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*separator);
    
    Gtk::Image* new_student_button_image = Gtk::manage(new Gtk::Image{"student.png"});
    Gtk::ToolButton *new_student_button;
    new_student_button = Gtk::manage(new Gtk::ToolButton(*new_student_button_image));
    new_student_button->set_tooltip_markup("New Student");
    new_student_button->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(*new_student_button);
    
  	Gtk::Image* new_parent_button_image = Gtk::manage(new Gtk::Image{"parent.png"});
    Gtk::ToolButton *new_parent_button;
    new_parent_button = Gtk::manage(new Gtk::ToolButton(*new_parent_button_image));
    new_parent_button->set_tooltip_markup("New Parent");
    new_parent_button->signal_clicked().connect([this] {this->on_new_parents_click();});
    toolbar->append(*new_parent_button);
    
    
	Gtk::Image* student_to_parent_button_image = Gtk::manage(new Gtk::Image{"student_and_parent.png"});
    Gtk::ToolButton *student_to_parent_button;
    student_to_parent_button = Gtk::manage(new Gtk::ToolButton(*student_to_parent_button_image));
    student_to_parent_button->set_tooltip_markup("Relate a parent to a student");
    student_to_parent_button->signal_clicked().connect([this] {this->on_student_to_parent_click();});
    toolbar->append(*student_to_parent_button);
    
        
    Gtk::SeparatorToolItem *separator2 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*separator2);
    
     //     O P E N  S C H O O L
    // Add a open school icon
    Gtk::ToolButton *view_courses_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    view_courses_button->set_tooltip_markup("Show Courses");
    view_courses_button->signal_clicked().connect([this] {this->show_data(2);});
    toolbar->append(*view_courses_button);
    
     //     S A V E  S C H O O L
    // Add a save school icon
    Gtk::ToolButton *view_section_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    view_section_button->set_tooltip_markup("Show Sections");
    view_section_button->signal_clicked().connect([this] {this->show_data(3);});
    toolbar->append(*view_section_button);
    
    // ////////////////////////////////////////////////////////////////////////
    // P E O P L E   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    display = Gtk::manage(new Gtk::Label());
	
	show_data(1);
    vbox->add(*display);
    

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new school
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
    show_data(1);
 
}

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
    Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_f = Gtk::FileFilter::create();
    filter_f->set_name("SAT files");
    filter_f->add_pattern("*.sat");
    dialog.add_filter(filter_f);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.sat");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();
    _filename = dialog.get_filename();
    
    if (result == 1) {
		 try {	

			std::ofstream ofs{_filename};
			for (auto p : parent)
			{
				p.save(ofs);
			}
			for (auto s : student)
			{
				s.save(ofs);
			}
			for (auto s : course)
			{
				s.save(ofs);
			}
			for (auto s : section)
			{
				s.save(ofs);
			}

			if(!ofs) throw std::runtime_error{"Error writing file"};
		
		} catch(std::exception& e) {
			Gtk::MessageDialog{*this, "Unable to save"}.run();
		} 
	    
	    
	}


}

void Mainwin::on_save_click() {

	if(_filename == "")
	{
	on_save_as_click();
	}
	else
	{
	  	try {	

			std::ofstream ofs{_filename};
			for (auto p : parent)
			{
				p.save(ofs);
			}
			for (auto s : student)
			{
				s.save(ofs);
			}

			if(!ofs) throw std::runtime_error{"Error writing file"};
		
		} catch(std::exception& e) {
			Gtk::MessageDialog{*this, "Unable to save"}.run();
		} 
	}

}


//
// The user wants to open a drawing from the filesystem
//
void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_f = Gtk::FileFilter::create();
    filter_f->set_name("SAT files");
    filter_f->add_pattern("*.sat");
    dialog.add_filter(filter_f);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.sat");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();
	int selector = 0; 
	int pa = 0;
	int st = 0;
	
	std::vector<std::vector<std::string>> par; 
	std::vector<std::vector<std::string>> stu;
	std::vector<std::string> inf;	
	if (result == 1) {
		on_new_school_click();
		
        try {
            
            std::ifstream ifs{dialog.get_filename()};
            if(!ifs) throw std::runtime_error{"File contents bad"};
            std::string q;
            while (std::getline(ifs , q))
            {
            	if(q == "Student")
				{
            		selector = 1;
            	}
            	else if (q == "Parent")
            	{
            		selector = 2;
            	}
            	else if (q == "End Parent")
            	{
            		par.push_back(inf);
            		inf.clear();
            		pa++;
            		
            	}
            	else if (q == "End Student")
            	{
            		stu.push_back(inf);
            		inf.clear();
            		st++;
            	}
            	else if (selector == 2)
            	{
            		inf.push_back(q);
            	}
            	else if (selector == 1)
            	{
            		inf.push_back(q);
            	}
            }
//
// creating parent and student
//    
		for (int i = 0; i < par.size(); i++) 
		{
		    parent.push_back(Parent{par[i][0], par[i][1]});
		}	

		for (int i = 0; i < stu.size(); i++) 
		{

		    student.push_back(Student{stu[i][0],stu[i][1], std::stoi(stu[i][2])});
		}
   
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open file"}.run();
        }
    }
//    
// maching Parent and student    
//    	
	for (int i = 0; i < par.size(); i++) 
	{
	    for (int j = 2 ; j <par.at(i).size(); j ++)
	  	{
	    	for (int k = 0; k < st; k++)
	    	{
	    		if (par.at(i).at(j) == student[k].to_string())
	    		{
	    			parent.at(i).add_student(student.at(k)); 
					student.at(k).add_parent(parent.at(i));
	    		}
	    	}
	    }
	}
	      
            
        
    

	show_data(1);


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
	
	show_data(1);
			



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
	show_data(1);
			

	
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
	
	if (c_stu.get_active_row_number() != -1 && c_par.get_active_row_number() != -1)
	{
		int s = c_stu.get_active_row_number();
		int p = c_par.get_active_row_number();
		parent.at(p).add_student(student.at(s)); 
		student.at(s).add_parent(parent.at(p));
	}
	   	
   	show_data(1);
}

void Mainwin::on_new_course(){
	Gtk::Dialog dialog{"Create a Course", *this};
    Gtk::Grid grid;
    
    Gtk::Label d_sec{"Pick a Subject"};
    Gtk::ComboBoxText c_sec{true}; 
	for (auto sec : sect )
	{
		c_sec.append(sec);
	}
	c_sec.set_active(0);
	
	grid.attach(d_sec, 1, 0, 1, 1); 
    grid.attach(c_sec, 1, 1, 2, 1);
    
    Gtk::Label lgrade{"Grade"};
    Gtk::SpinButton sgrade;
    sgrade.set_range(1,12);
    sgrade.set_increments(1,5);       
    sgrade.set_value(10);              

    grid.attach(lgrade, 1, 2, 1, 1);
    grid.attach(sgrade, 1, 3, 2, 1);

    
	dialog.get_content_area()->add(grid);

    dialog.add_button("Ok", Gtk::RESPONSE_CANCEL); 
    dialog.add_button("Cancle", Gtk::RESPONSE_ACCEPT); 
    int response;

    dialog.show_all();

    while((response = dialog.run()) == Gtk::RESPONSE_OK) {}
    //waits till the cancle button disquized as an OK button is selected
    int s = c_sec.get_active_row_number();
    if (response == Gtk::RESPONSE_ACCEPT)
    {

    }
    else if (sect.at(s) == "Reading")
    {;
    	course.push_back(Course{Subject::READING,sgrade.get_value_as_int()});
    }
    else if (sect.at(s) == "Writing")
    {
    	course.push_back(Course{Subject::WRITING,sgrade.get_value_as_int()});
    }
    else if (sect.at(s) == "Math")
    {
    	course.push_back(Course{Subject::MATH,sgrade.get_value_as_int()});
    }
    else if (sect.at(s) == "Science")
    {
    	course.push_back(Course{Subject::SCIENCE,sgrade.get_value_as_int()});
    }
    else if (sect.at(s) == "History")
    {
    	course.push_back(Course{Subject::HISTORY,sgrade.get_value_as_int()});
    }
    else if (sect.at(s) == "Art")
    {
    	course.push_back(Course{Subject::ART,sgrade.get_value_as_int()});
    }
	
}
void Mainwin::on_new_section(){
	lett.str("");
	std::string str;
	Gtk::Dialog dialog{"Create a Section", *this};
    Gtk::Grid grid;
    
    Gtk::Label d_sec{"Pick a Course"};
    Gtk::ComboBoxText c_sec{true}; 
	for (auto sec : course)
	{
		lett << sec;
		str = lett.str();
		c_sec.append(str);
		lett.str("");
	}
	c_sec.set_active(0);
	
	grid.attach(d_sec, 0, 0, 1, 1); 
    grid.attach(c_sec, 0, 1, 2, 1);
    
    Gtk::Label lyear{"Enter the Year(2000-2022)"};
    Gtk::SpinButton syear;
    syear.set_range(2000,2021);
    syear.set_increments(1,5);       
    syear.set_value(2020);              

    grid.attach(lyear, 0, 3, 1, 1);
    grid.attach(syear, 0, 4, 2, 1);

 	Gtk::Label d_sem{"Pick a Semester"};
    Gtk::ComboBoxText c_sem{true}; 
	for (auto sem : semester )
	{
		c_sem.append(sem);
	}
	c_sem.set_active(0);
	
	grid.attach(d_sem, 0, 5, 1, 1); 
    grid.attach(c_sem, 0, 6, 2, 1);
    
	dialog.get_content_area()->add(grid);

    dialog.add_button("Ok", Gtk::RESPONSE_CANCEL); 
    dialog.add_button("Cancle", Gtk::RESPONSE_ACCEPT); 
    int response;

    dialog.show_all();

    while((response = dialog.run()) == Gtk::RESPONSE_OK) {}
    //waits till the cancle button disquized as an OK button is selected
    int s = c_sem.get_active_row_number();
    int p = c_sec.get_active_row_number();
    if (response == Gtk::RESPONSE_ACCEPT)
    {

    }
    else if (semester.at(s) == "Fall")
    {
    	section.push_back(Section{course.at(p), Semester::FALL, syear.get_value_as_int()});
    }
    else if (semester.at(s) == "Spring")
    {
    	section.push_back(Section{course.at(p), Semester::SPRING, syear.get_value_as_int()});
    }
    else if (semester.at(s) == "Summer")
    {
    	section.push_back(Section{course.at(p), Semester::SUMMER, syear.get_value_as_int()});
    }






}

void Mainwin::show_data(int a) {
	lett.str("");
	std::string s;
	if (a == 1){
		s = "\tParents:\n\n";
		for (auto par : parent )
		{
			s += par.full_info();
		}
		s += "\n\tStudents:\n\n";
		for (auto stu : student )
		{
			s+= stu.full_info();
		}

		display->set_markup(s);
	}
	else if (a == 2)
	{
		lett << "\tCourses:\n\n";
		for (auto cour : course)
		{
			lett << cour;
		}
		s = lett.str();
		display->set_markup(s);
	}
	else if (a == 3)
	{
		lett << "\tSections:\n\n";
		for (auto sect : section)
		{
			lett << sect;
		}
		s = lett.str();
		display->set_markup(s);
	}	
		
}

void Mainwin::on_easter_egg() {
    const std::vector<std::string> names{
        "Enrique Young",  // student
        "Isabella Young", // student
        "Biniti Adani", // student
        "James Montgomery", //student
        "Robert Young",
        "Susan Young",
        "Nimish Adani",
        "Oscar Montgomery",
      };
    const std::vector<std::string> emails{
        "eyoung@gmale.com",
        "iyoung@fmale.com",
        "biniti@myschool.org",
        "james.q.montgomery@british.uk",
        "bob-young@woohoo.com",
        "youngsr@uta.edu",
        "nimish.adani@hatmail.com",
        "oscar.the.m@funville.net",
      };
    const std::vector<int> grades {
          1, 5, 3, 12, // For students only
      };
    try {
        on_new_school_click();
        for(int i=0; i<grades.size(); ++i)
            student.push_back(Student{names[i], emails[i], grades[i]});
        for(int i=grades.size(); i<names.size(); ++i)
           parent.push_back(Parent{names[i], emails[i]});
        student[0].add_parent(parent[0]); parent[0].add_student(student[0]);
        student[0].add_parent(parent[1]); parent[1].add_student(student[0]);
        student[1].add_parent(parent[0]); parent[0].add_student(student[1]);
        student[1].add_parent(parent[1]); parent[1].add_student(student[1]);
        student[2].add_parent(parent[2]); parent[2].add_student(student[2]);
        student[2].add_parent(parent[1]); parent[1].add_student(student[2]);
        student[3].add_parent(parent[1]); parent[1].add_student(student[3]);
        student[3].add_parent(parent[2]); parent[2].add_student(student[3]);
        student[3].add_parent(parent[3]); parent[3].add_student(student[3]);
        show_data(1);
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, e.what()}.run();
    }
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("S.M.A.R.T.");
    auto logo = Gdk::Pixbuf::create_from_file("19197906.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 0.2.0");
    dialog.set_copyright("Copyright 2021-2022");
    dialog.set_license_type(Gtk::License::LICENSE_AGPL_3_0_ONLY);
    std::vector< Glib::ustring > authors = {"Sworup Bhattarai"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logo by macrovector, licensed under CC BY-SA 3.0  https://image.freepik.com/free-vector/school-building-with-without-textures_1284-52251.jpg",
        "Student and Parent Icons made by Freepik, licensed under CC BY-SA 3.0  https://www.flaticon.com/packs/social-media-81",
        "Made in collabration with Professor George F. Rice from The Univercity Of Texas At Arlington https://github.com/prof-rice"};
    dialog.set_artists(artists);
    dialog.run();
}




