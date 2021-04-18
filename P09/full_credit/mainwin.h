#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include <ostream>
#include <istream>
#include <vector>
#include <iostream>
#include <sstream>
#include "person.h"
#include "parent.h"
#include "student.h"
#include "subject.h"
#include "section.h"
#include "course.h"
#include "semester.h"
#include "transcript.h"
#include "grade.h"
#include "teacher.h"


class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_school_click();          // Create a new school 
        void on_new_student_click();       
        void on_new_parents_click();     
        void on_quit_click();		     // Exit the game
        void on_student_to_parent_click();  
        void on_save_as_click();           // Save the game to a file
        void on_save_click();
        void on_open_click(); 
        void on_easter_egg(); 
        void on_about_click(); 
        void on_new_course();
        void on_new_section();
        void on_new_transcript();
        void on_set_grade();
        
        
                 
    private:
		std::vector<Student> student;
		std::vector<Parent> parent;
		std::vector<Course> course;
		std::vector<Section> section;
		std::vector<Transcript> transcripts;
		std::vector<std::string> sect;
		std::vector<std::string> semester;
		std::vector<std::string> grade;
		Gtk::Label *display;                      // Display of sticks on game board
		void show_data(int a);
		std::string _filename;
		std::ostringstream lett;
		
	
};
#endif 

