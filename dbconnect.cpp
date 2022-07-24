// program to connect to mysql database
#include <iostream>
#include <mysql/mysql.h>

#include <string>
#include <sstream>

using namespace std;
#define HOST "127.0.0.1"
#define USER "root"
#define PASSWORD "root123"
#define DATABASE "test"
#define PORT 3306

MYSQL *conn;
MYSQL_RES *res_set;
MYSQL_ROW row;
stringstream stmt;
const char *q;
string query;

class books
{
  int id;
  string title;
  string author;
  int price;
  int qty;

public:
  void add_book();
  void show_book();
  void update_book();
  void delete_book();
  void search_book();
};

void books::add_book()
{
  cout << "Enter the book id: ";
  cin >> id;
  cout << "Enter the book title: ";
  cin >> title;
  cout << "Enter the book author: ";

  cin >> author;
  cout << "Enter the book price: ";
  cin >> price;
  cout << "Enter the book quantity: ";
  cin >> qty;
  stmt.str("");
  stmt << "insert into books values(" << id << ",'" << title << "','" << author << "'," << price << "," << qty << ")";
  query = stmt.str();
  q = query.c_str();
  stmt.clear();
  mysql_query(conn, q);
  res_set = mysql_store_result(conn);
  res_set = mysql_store_result(conn);
  if (!(res_set))
    cout << endl
         << endl
         << "Book Record Inserted Successfully" << endl
         << endl
         << endl;
  else
    cout << endl
         << endl
         << "Entry ERROR !" << endl
         << "Contact Technical Team " << endl
         << endl
         << endl;
}

void books::update_book()
{
  cout << "Enter the book id: ";
  cin >> id;
  cout << "Enter the book title: ";
  cin >> title;
  cout << "Enter the book author: ";
  cin >> author;
  cout << "Enter the book price: ";
  cin >> price;
  cout << "Enter the book quantity: ";
  cin >> qty;
  stmt << "update books set title='" << title << "',author='" << author << "',price=" << price << ",qty=" << qty << " where id=" << id;
  query = stmt.str();
  q = query.c_str();
  mysql_query(conn, q);
  res_set = mysql_store_result(conn);
  if (!(res_set))
    cout << endl
         << endl
         << "Book Record Updated Successfully" << endl
         << endl
         << endl;
  else
    cout << endl
         << endl
         << "Entry ERROR !" << endl
         << "Contact Technical Team " << endl
         << endl
         << endl;
}

void books::search_book()
{
  cout << "Enter the book id: ";
  cin >> id;
  query = stmt.str();
  stmt.str("");
  stmt << "select * from books where id=" << id;

  stmt.clear();
  q = query.c_str();
  // conn->query(query.c_str());
  res_set = mysql_store_result(conn);
  row = mysql_fetch_row(res_set);
  if (row != NULL)
  {
    cout << "Book id: " << row[0] << endl;
    cout << "Book title: " << row[1] << endl;
    cout << "Book author: " << row[2] << endl;
    cout << "Book price: " << row[3] << endl;
    cout << "Book quantity: " << row[4] << endl;
  }
  else
    cout << "No record found" << endl;
  cout << "Book id: " << row[0] << endl;
  cout << "Book title: " << row[1] << endl;
  cout << "Book author: " << row[2] << endl;
  cout << "Book price: " << row[3] << endl;
  cout << "Book quantity: " << row[4] << endl;
}
void books::delete_book()
{
  cout << "Enter the book id: ";
  cin >> id;
  stmt << "delete from books where id=" << id;
  query = stmt.str();
  stmt.str("");
  stmt.clear();
  q = query.c_str();
  mysql_query(conn, q);
}
void books::show_book()
{
  stmt << "select * from books";
  query = stmt.str();
  stmt.str("");
  stmt.clear();
  q = query.c_str();
  res_set = mysql_store_result(conn);
  while ((row = mysql_fetch_row(res_set)))
  {
    cout << "Book id: " << row[0] << endl;
    cout << "Book title: " << row[1] << endl;
    cout << "Book author: " << row[2] << endl;
    cout << "Book price: " << row[3] << endl;
    cout << "Book quantity: " << row[4] << endl;
  }
  {
    cout << "Book id: " << row[0] << endl;
    cout << "Book title: " << row[1] << endl;
    cout << "Book author: " << row[2] << endl;
    cout << "Book price: " << row[3] << endl;
    cout << "Book quantity: " << row[4] << endl;
  }
}

void main_menu()
{
  int c;
  books b;
  cout << "*************************************************" << endl;
  cout << "                  BOOK MENU" << endl;
  cout << "*************************************************" << endl;
  cout << "   1. ADD" << endl;
  cout << "   2. UPDATE Book" << endl;
  cout << "   3. SEARCH" << endl;
  cout << "   4. DELETE BOOK" << endl;
  cout << "   5. DISPLAY ALL" << endl;
  cout << "   6. RETURN TO MAIN MENU" << endl
       << endl
       << endl;
  cout << "Enter Your Choice : ";
  cin >> c;
  switch (c)
  {
  case 1:
    b.add_book();
    break;
  case 2:
    b.update_book();
    break;
  case 3:
    b.search_book();
    break;
  case 4:
    b.delete_book();
    break;
  case 5:
    b.show_book();
    break;
  case 6:
    main_menu();
    break;
  default:
    cout << "Invalid Choice" << endl;
    main_menu();
    break;
  }
}
int main()
{
  conn = mysql_init(0);
  conn = mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, PORT, NULL, 0);

  if (conn)
  {
    while (1)
    {
      main_menu();
    }

    cout << "Connection Successful" << endl;
  }
  else
  {
    cout << "Connection Failed" << endl;
    return 0;
  }
}
