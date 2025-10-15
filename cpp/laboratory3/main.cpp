#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <limits> 
#include "utils.h"

// The life/time saver
using namespace std;
using namespace this_thread;
using namespace chrono;

// Settup defines
#define SLEEP_INTERVAL 2
#define MAX_BUF_SIZE 1000000

// Creating custom data type
struct Article {
  string title;
  vector<string> authors;
  string date;
  string resume;
  vector<string> key_words;
  string content;
  vector<string> article_types;
};

// DATA_BASE/db intialisation
class DATA_BASE {
  vector<Article> articles;
  public:
    void add(Article article) { articles.push_back(article); }
    vector<Article> get() { return articles; };
};
DATA_BASE db;

// Custom exteption
struct ExitInput : public exception {};

string FILTER_VAR = "blacklist date 10.10.10";

// Globalisation for some funcitons
void welcome_page(); 
void article_actions(Article article);
void show_articles();

// Function for adding an new article in db
void add_article() {
  clear_all();
  show_header("  ADD NEW ARTICLE  ");
  cout << "Tip: Type '-exit' to terminate the process.\n\n";
  
  Article article;

  try {
    cout << "Type article title: ";
    safe_input(article.title, MAX_BUF_SIZE);

    cout << "Type article authors, (-e) for finish:" << endl;
    write_vector(article.authors);

    cout << "Type article date (dd.mm.yyyy): ";
    safe_input(article.date, 10);
    
    cout << "Type article resume: ";
    safe_input(article.resume, MAX_BUF_SIZE);
    
    cout << "Type article key words, (-e) for finish:" << endl;
    write_vector(article.key_words);
    
    cout << "Type article content: ";
    safe_input(article.content, MAX_BUF_SIZE);
    
    cout << "Type article types, (-e) for finish:" << endl;
    write_vector(article.article_types);

    db.add(article);
    welcome_page();
  } catch (ExitInput&) {
    welcome_page();
  }
}

// Show the content of choised article
void show_article_content(Article article) {
  int separator_len = 100;
  cout << endl;
  write_line('-', separator_len);
  cout << "AUTHORS: " << vector_out(article.authors, ", ") << endl;
  write_line('-', separator_len);
  cout << "DATE: " << article.date << endl;
  write_line('-', separator_len);
  cout << "RESUME: " << article.resume << endl;
  write_line('-', separator_len);
  cout << "KEY WORDS: " << vector_out(article.key_words, ", ") << endl;
  write_line('-', separator_len);
  cout << "CONTENT: " << article.content << endl;
  write_line('-', separator_len);
  cout << "ARTICLE TYPES: " << vector_out(article.article_types, ", ") << endl;
  write_line('-', separator_len);
  cout << endl;

  while (true) {
    string choise;
    cout << "Type command: ";
    cin >> choise;
    
    if (choise == "-e") return show_articles();
    if (choise == "-exit") return welcome_page();

    clear_line(1);
    cout << "[-] Invalied command." << endl;
    sleep_for(seconds(2));
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clear_line(1);
  }
}

// Show all articles which are in db
void show_articles() {
  clear_all();
  show_header("  ARTICLES  ");
  cout << endl;

  vector<Article> articles = db.get();
  for (int i = 0; i < articles.size(); ++i) {
    cout << (i + 1)  << ") " << articles[i].title << endl;
  }

  string input;
  cout << "Type article num '-e' to exit: ";
  getline(cin, input);

  if (input == "-e") {
    return welcome_page();
  }

  int article_idx; 
  try {
      size_t pos;
      article_idx = stoi(input, &pos);

      if (pos != input.size()) throw invalid_argument("Extra characters");

      if (article_idx < 1 || article_idx > articles.size()) {
          cout << "Index out of range.\n";
          return welcome_page();
      }

  } catch (...) {
      cout << "Invalid input. Returning to menu.\n";
      return welcome_page();
  }

  article_actions(articles[article_idx - 1]);
}

void make_filter() {
  show_header("  MAKE FILTER  ");
  cout << "TIP: Type -e to main menu";
  cout << "TIP: Filter structure: filter-type target-type target-content";
  cout << endl;
  
  cout << "Write filter"; 

}

// Actions processor for main (welcome) page
void action_process(int action_num) {
  switch (action_num) {
    case 1:
      add_article();
      break;
    case 2:
      show_articles();
      break;
    case 3:
      make_filter();
    default:
      clear_line(1);
      cerr << "Something went wrong, please try again.";
      sleep_for(seconds(SLEEP_INTERVAL));
      welcome_page();
      break;
  }
}

// Make an menu for user's choise
void article_actions(Article article) {
  clear_all();
  show_header("  " + article.title + "  ");
  cout << "TIP: Type '-e' to go back or '-exit' to main menu" << endl;

  string choise;
  cout << "1) Show article content." << endl;
  cout << "2) Change article content." << endl;
  cout << "Chooise action: ";
  cin >> choise;
  
  if (choise == "-exit") return welcome_page();
  if (choise == "-e") return show_articles();

  try {
    switch (stoi(choise)) {
      case 1:
        clear_line(3);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        show_article_content(article);
        break;
      default:
        clear_line(1);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[-] Something wrong, please try again.";
        sleep_for(seconds(2));
        article_actions(article);
        break;
    }
  } catch (...) {
    clear_line(1);
    cerr << "[-] Invalied input, type num or command.";
    sleep_for(seconds(2));
    article_actions(article);
  }
}

// Debug function which input in db some articles for testing
void debug_add_articles() {
    Article a1;
    a1.title = "The Future of AI";
    a1.authors = {"John Doe", "Alice Smith"};
    a1.date = "2025-10-01";
    a1.resume = "An overview of artificial intelligence development trends.";
    a1.key_words = {"AI", "machine learning", "future"};
    a1.content = "Artificial intelligence is rapidly evolving, impacting all industries...";
    a1.article_types = {"Research", "Technology"};
    db.add(a1);

    Article a2;
    a2.title = "Climate Change Effects";
    a2.authors = {"Robert Brown"};
    a2.date = "2024-06-15";
    a2.resume = "A study of environmental impact caused by human activity.";
    a2.key_words = {"climate", "environment", "pollution"};
    a2.content = "The global climate is changing faster than predicted...";
    a2.article_types = {"Science", "Environment"};
    db.add(a2);

    Article a3;
    a3.title = "Quantum Computing Basics";
    a3.authors = {"Maria Johnson", "Leo Clark"};
    a3.date = "2025-01-22";
    a3.resume = "Introduction to quantum computing and its potential applications.";
    a3.key_words = {"quantum", "computing", "physics"};
    a3.content = "Quantum computers use qubits to perform parallel calculations...";
    a3.article_types = {"Education", "Technology"};
    db.add(a3);
}

// Function for user choise processing  
int show_menu() {  
  cout << "1) Add new article." << endl;
  cout << "2) Show articles." << endl;
  cout << "3) Make filter." << endl; 
  
  while (true) {
    int input;
    cout << "Choice the action number: ";

    if (!(cin >> input)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      clear_line(1);
      cerr << "[-] Invalid input. Please enter a number." << endl;
      sleep_for(seconds(SLEEP_INTERVAL));
      clear_line(1);
      continue;
    }

    if (input < 1 || input > 3) {
      clear_line(1);
      cerr << "[-] Invalid choice." << endl;
      sleep_for(seconds(SLEEP_INTERVAL));
      clear_line(1);
      continue;
    }
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
  }
}

// Main page of program
void welcome_page() {
  clear_all();
  show_header("  WELCOME TO MORRIS DB  ");
  cout << endl;
  // The function returns an integer 'choice' 
  // which is used for processing in 'action_process' functon.
  int choise = show_menu();
  action_process(choise);
}

int main() {
  debug_add_articles();
  welcome_page();

  return 0;
}

