#include <iostream>
#include <sqlite3.h>

using namespace std;

int main(int argc, char *argv[]){
	sqlite3 *db = NULL;
	sqlite3_stmt *stmt = NULL;
	string query1, query2;
	int res;

	if(sqlite3_open("sqldb.db",&db) != SQLITE_OK){
		cout<<"Failed to connect!";
		return 0;
	}

	query1 = "insert into regUsr(timestamp , imgBLOB) select timestamp , imgBLOB from users where timestamp = ?;";
	sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL );
	sqlite3_bind_blob(stmt,1,agv[1],sizeof(argv[1])+1,SQLITE_TRANSIENT);
    res = sqlite3_step(stmt);

    query2 = "insert into regUsr(name) values (?) where timestamp = ?"
    sqlite3_prepare(db, query.c_str(), -1, &stmt, NULL );
	sqlite3_bind_text(stmt,1,argv[2],-1,SQLITE_TRANSIENT);
	sqlite3_bind_blob(stmt,1,agv[1],sizeof(argv[1])+1,SQLITE_TRANSIENT);
    res = sqlite3_step(stmt);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}