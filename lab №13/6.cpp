#include "iostream"
#include "string"
#include "vector"
#include "regex"
using namespace std;

vector<string> each_str_po_otdel;

regex fio("^([A-Z])([a-z]*)$");
regex vozrast("^[0-9]{2}$");
regex phone(R"(^((8|\+7)[\- ]?)?(\(?\d{3}\)?[\- ]?)?[\d\- ]{7,10}$)");
regex town("^(g.)[A-Z][A-Z][A-Z],$");
regex avenue("^(ul.)[A-Z]([a-z]*),$");
regex building("^(d.)([0-9]+)$");

int main() {
    int M;
    cin >> M;
    string musor;
    getline(cin, musor);

    for (int i = 0; i < M; i++) {

        string vvod;
        getline(cin, vvod);

        string part_of_full_str;
        for (int j = 0; j < vvod.size(); j++) {
            if (vvod[j] == ' ') {
                each_str_po_otdel.emplace_back(part_of_full_str);
                part_of_full_str.clear();
            } else {
                part_of_full_str.push_back(vvod[j]);
            }
        }
        each_str_po_otdel.emplace_back(part_of_full_str);
        if (each_str_po_otdel.size() != 8) {
            cout << "NO" << "\n";
            each_str_po_otdel.clear();
            continue;
        }

        if (!regex_match(each_str_po_otdel[0], fio) or !regex_match(each_str_po_otdel[1], fio) or !regex_match(each_str_po_otdel[2], fio) or !regex_match(each_str_po_otdel[3], vozrast) or !regex_match(each_str_po_otdel[4], phone) or !regex_match(each_str_po_otdel[5], town) or !regex_match(each_str_po_otdel[6], avenue) or !regex_match(each_str_po_otdel[7], building)) {
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
        }
        each_str_po_otdel.clear();
    }
    return 0;
}
