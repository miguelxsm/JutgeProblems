#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Client {
    string client_id;
    Date birth_date;
    bool priority;
    int total_amount;
};

//returns true when client a is older than b. Returns false otherwise
bool is_older(const Client& a, const Client& b) {
    Date x = a.birth_date;
    Date y = b.birth_date;
    if (x.year != y.year) return x.year < y.year;
    if (x.month != y.month) return x.month < y.month;
    return x.day < y.day;
}

void get_client(Client& a) {
    int n;
    a.total_amount = 0;
    int compras_mas_de_mil = 0;
    cin >> a.client_id >> a.birth_date.day >> a.birth_date.month >> a.birth_date.year >> n;
    int importe;
    for (int i = 0; i < n; ++i) {
        cin >> importe;
        if (importe >= 1000) ++compras_mas_de_mil;
        a.total_amount += importe;
    }
    if (compras_mas_de_mil >= 3) a.priority = true;
    else a.priority = false;
}

//gets client info vector v
void get_client_vector(vector<Client>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) get_client(v[i]);
}



//prints date info in format dd-mm-yyyy
void print_date(Date date) {
    if (date.day < 10) cout << 0;
    cout << date.day << '-';
    if (date.month < 10) cout << 0;
    cout << date.month << '-';
    cout << date.year;
}

//writes v on output channel
void write_client_vector(const vector<Client>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        cout << v[i].priority << ' ' << v[i].total_amount << ' ';
        print_date(v[i].birth_date);
        cout << ' ' << v[i].client_id << endl;
    }
}

bool cmp(Client& a, Client& b) {
    if (a.priority != b.priority) return a.priority;
    if (a.total_amount != b.total_amount) return a.total_amount > b.total_amount;
    if (a.birth_date.day != b.birth_date.day or a.birth_date.month != b.birth_date.month or a.birth_date.year != b.birth_date.year) return is_older(a,b);
    return a.client_id < b.client_id;
}

int main() {
    int n;
    cin >> n;
    vector<Client> v(n);
    get_client_vector(v);
    sort(v.begin(),v.end(),cmp);
    write_client_vector(v);
}
