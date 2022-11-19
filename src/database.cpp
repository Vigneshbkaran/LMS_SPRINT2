#include <iostream>
#include <sqlite3.h>
using namespace std;

int main(int argc, char** argv)
{
	sqlite3* DB;
	string sql = "DROP TABLE IF EXISTS RECORD;"
		    "CREATE TABLE RECORD(BookID INT, Name TEXT, URL TEXT);"
                    "INSERT INTO RECORD VALUES(1, 'Audi', 'www.pdfdrive.com/download.pdf?id=194278645&h=6799a1ed0fa63af1e43c3534ad141406&u=cache&ext=pdf');"
                    "INSERT INTO RECORD VALUES(2,'Mercedes', 'www.pdfdrive.com/download.pdf?id=194278645&h=6799a1ed0fa63af1e43c3534ad141406&u=cache&ext=pdf');"
                    "INSERT INTO RECORD VALUES(3,'skoda', 'www.pdfdrive.com/download.pdf?id=194278646&h=6799a1ed0fa63af1e43c3534ad141406&u=cache&ext=pdf');";
                    //"INSERT INTO RECORD VALUES(4,'Volvo', 'Audi');"
                    //"INSERT INTO RECORD VALUES(5,'Bentley', 'Audi');";
	int exit = 0;
	exit = sqlite3_open("books.db", &DB);
	char* messaggeError;
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

	if (exit != SQLITE_OK) {
		cerr << "Error Create Table" << endl;
		sqlite3_free(messaggeError);
	}
	else
		cout << "Table created Successfully" << endl;
	sqlite3_close(DB);
	return (0);
}

