#include <iostream>
#include <sqlite3.h>
using namespace std;

int main(int argc, char** argv)
{
	sqlite3* DB;
	string sql = "DROP TABLE IF EXISTS RECORD;"
                    "CREATE TABLE RECORD(BookID INT, Name TEXT, AuthorName TEXT);"
                    "INSERT INTO RECORD VALUES(1, 'Audi', 'Audi');"
                    "INSERT INTO RECORD VALUES(2,'Mercedes', 'Audi');"
                    "INSERT INTO RECORD VALUES(3,'skoda', 'Audi');"
                    "INSERT INTO RECORD VALUES(4,'Volvo', 'Audi');"
                    "INSERT INTO RECORD VALUES(5,'Bentley', 'Audi');";
	int exit = 0;
	exit = sqlite3_open("record.db", &DB);
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

