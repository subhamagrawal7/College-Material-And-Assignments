#include<bits/stdc++.h>

using namespace std;

map<string, int> symbol_table, POT;

int convert(const string &s, int res = 0) {
        for (char i: s) res = res * 10 + (i - '0');
        return res;
}

void inIt() {
        POT["START"] = 1;
        POT["END"] = 2;
        POT["EQU"] = 3;
        POT["ORIGIN"] = 4;
        POT["LTORG"] = 5;
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        inIt();
        int lc = 0;
        int line;
        cin >> line;
        int cntLiteral = 0;
        string s;
        while (line--) {
                getline(cin, s);
                int n = s.length();

                if (s.find(':') != -1) {
                        string labelName = s.substr(0, s.find(':'));

                        // if it contains EQU
                        if (s.find("EQU") != -1) {
                                int ptr = s.find("EQU") + 3;
                                while (s[ptr] == ' ') ptr++;
                                string ref = s.substr(ptr);
                                symbol_table[labelName] = symbol_table[ref];
                                continue;
                        }

                        // else generate lc for it
                        symbol_table[labelName] = lc;
                        lc++;
                        continue;
                }

                if (s.find("START") != -1) {
                        int ptr = s.find("START") + 5;
                        while (s[ptr] == ' ') ptr++;
                        int num = convert(s.substr(ptr));
                        // setting location counter
                        lc = num;
                }

                if (s.find("LTORG") != -1) {
                        lc += cntLiteral;
                        continue;
                }

                if (s.find('=') != -1) {
                        cntLiteral++;
                }

                if (s.find("ADD") != -1 || s.find("SUB") != -1 || s.find("MULT") != -1 || s.find("MOVER") != -1 || s.find("MOVEM") != -1 || s.find("COMP") != -1 || s.find("BC") != -1 || s.find("DIV") != -1 || s.find("READ") != -1 ||
                    s.find("PRINT") != -1) {
                        // here we can't find any symbol address.
                        lc++;
                        continue;
                }

                if (s.find(" DC ") != -1 || s.find(" DS ") != -1) {
                        string symbolName;
                        int ptr = 0;
                        while (s[ptr] != ' ') symbolName += string(1, s[ptr++]);
                        symbol_table[symbolName] = lc;
                        lc++;
                }

                if (s.find("ORIGIN") != -1) {
                        int ptr = s.find("ORIGIN") + 6;
                        while (s[ptr] == ' ') ptr++;
                        int num = convert(s.substr(ptr));
                        // setting location counter
                        lc = num;
                }
        }

        cout << "SYMBOL TABLE" << "\n";
        cout << "SYMBOL\tADD\n";
        for (const auto& it: symbol_table) {
                string symbol = it.first;
                int ADD = it.second;
                cout << symbol << "\t" << ADD << "\n";
        }

        cout << "\nPSEUDO OPCODE TABLE" << "\n";
        for (const auto& it: POT) {
                string symbol = it.first;
                int ADD = it.second;
                cout << symbol << "\t" << ADD << "\n";
        }
        return 0;
}


