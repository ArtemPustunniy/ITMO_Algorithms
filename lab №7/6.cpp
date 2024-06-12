#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


int main(){
    int n, m;
    long long k;
    cin >> n >> m >> k;
    string first_RLE;
    string second_RLE;
    cin >> first_RLE;
    cin >> second_RLE;
    // Первое заполнение
    char now_1 = (char) first_RLE[0];
    char now_2 = (char) second_RLE[0];
    long long counter = 0;
    int k1 = 1;
    int k2 = 1;
    string post_1;
    string post_2;
    long long delta_now;
    int perfect;
    while(isdigit(first_RLE[k1])){
        post_1 += first_RLE.substr(k1, 1);
        k1++;
    }
    if (post_1.empty()){
        post_1 = "1";
    }
    while(isdigit(second_RLE[k2])){
        post_2 += second_RLE.substr(k2, 1);
        k2++;
    }
    if (post_2.empty()){
        post_2 = "1";
    }
    if (stoll(post_1) >  stoll(post_2)){
        delta_now = stoll(post_1) - stoll(post_2);
        perfect = 1;
        if (now_1 != now_2){
            counter += stoll(post_2);
        }
    }
    if (stoll(post_1) <  stoll(post_2)){
        delta_now = stoll(post_2) - stoll(post_1);
        perfect = 2;
        if (now_1 != now_2){
            counter += stoll(post_1);
        }
    }
    if (stoll(post_1) ==  stoll(post_2)){
        delta_now = 0;
        perfect = 0;
        if (now_1 != now_2){
            counter += stoll(post_1);
        }
    }
    post_1.clear();
    post_2.clear();
    //cout << delta_now << "\n";
    //int exition = 0;

    while (true){
        //cout << counter << " " << delta_now << " " << perfect << " " << k1 << " " << k2 << "\n";
//        if (exition > 2){
//            break;
//        }
//        exition++;
        if (counter > k || (k1 >= first_RLE.size() && k2 >= second_RLE.size())){
            break;
        }
        // Первая строка ушла дальше второй
        if (perfect == 1){
            // Если вторая строка кончилась
            if (k2 >= second_RLE.size()){
                // Если первая строка так же кончилась
                if (k1 >= first_RLE.size()){
                    counter += delta_now;
                    break;
                }
                // Если первая строка не кончилась
                else{
                    counter += delta_now;
                    while (k1 < first_RLE.size() - 1) {
                        now_1 = first_RLE[k1];
                        k1++;
                        while (isdigit(first_RLE[k1])) {
                            post_1 += first_RLE.substr(k1, 1);
                            k1++;
                        }
                        if (post_1.empty()) {
                            post_1 = "1";
                        }
                        counter += stoll(post_1);
                        post_1.clear();
                    }
                    break;
                }
            }
            // Если только первая строка кончилась
            else if (k1 >= first_RLE.size()){
                // Пока не дойдём до конца сторой строки
                while (k2 < second_RLE.size() - 1){
                    now_2 = second_RLE[k2];
                    k2++;
                    while(isdigit(second_RLE[k2])){
                        post_2 += second_RLE.substr(k2, 1);
                        k2++;
                    }
                    if (post_2.empty()){
                        post_2 = "1";
                    }
                    if (delta_now > stoll(post_2)){
                        delta_now -= stoll(post_2);
                        if (now_1 != now_2){
                            counter += stoll(post_2);
                        }
                    }
                    else if(delta_now < stoll(post_2)){
                        if (now_1 != now_2){
                            counter += stoll(post_2);
                        }
                        post_2.clear();
                        while(k2 < second_RLE.size() - 1){
                            now_2 = second_RLE[k2];
                            k2++;
                            while (isdigit(second_RLE[k2])) {
                                post_2 += second_RLE.substr(k2, 1);
                                k2++;
                            }
                            if (post_2.empty()) {
                                post_2 = "1";
                            }
                            counter += stoll(post_2);
                            post_2.clear();
                        }
                    }
                    else{
                        if (now_1 != now_2){
                            counter += delta_now;
                        }
                        delta_now = 0;
                        post_2.clear();
                        while(k2 < second_RLE.size() - 1){
                            now_2 = second_RLE[k2];
                            k2++;
                            while (isdigit(second_RLE[k2])) {
                                post_2 += second_RLE.substr(k2, 1);
                                k2++;
                            }
                            if (post_2.empty()) {
                                post_2 = "1";
                            }
                            counter += stoll(post_2);
                            post_2.clear();
                        }

                    }
                    post_2.clear();
                }
                break;
            }
            // Общий случай
            now_2 = second_RLE[k2];
            k2++;
            while(isdigit(second_RLE[k2])){
                post_2 += second_RLE.substr(k2, 1);
                k2++;
            }
            if (post_2.empty()){
                post_2 = "1";
            }

            if (delta_now > stoll(post_2)){
                delta_now -= stoll(post_2);
                if (now_1 != now_2){
                    counter += stoll(post_2);
                }
            }
            else if(delta_now < stoll(post_2)){
                if (now_1 != now_2){
                    counter += delta_now;
                }
                delta_now = stoll(post_2) - delta_now;
                perfect = 2;
            }
            else{
                if (now_1 != now_2){
                    counter += delta_now;
                }
                delta_now = 0;
                perfect = 0;
            }
            post_2.clear();
        }
        // Вторая строка ушла дальше первой
        else if(perfect == 2){
            // Если первая строка кончилась
            if (k1 >= first_RLE.size()){
                // Если вторая строка так же кончилась
                if (k2 >= second_RLE.size()){
                    counter += delta_now;
                    break;
                }
                // Если вторая строка не кончилась
                else{
                    counter += delta_now;
                    while (k2 < second_RLE.size() - 1) {
                        //cout << k2 << "---" << "\n";
                        now_2 = second_RLE[k2];
                        k2++;
                        while (isdigit(second_RLE[k2])) {
                            post_2 += second_RLE.substr(k2, 1);
                            k2++;
                        }
                        if (post_2.empty()) {
                            post_2 = "1";
                        }
                        //cout << post_2 << "---" << "\n";
                        counter += stoll(post_2);
                        post_2.clear();
                    }
                    break;
                }
            }
            // Если только вторая строка кончилась
            else if(k2 >= second_RLE.size()) {
                while (k1 < first_RLE.size() - 1) {
                    now_1 = first_RLE[k1];
                    k1++;
                    while (isdigit(first_RLE[k1])) {
                        post_1 += first_RLE.substr(k1, 1);
                        k1++;
                    }
                    if (post_1.empty()) {
                        post_1 = "1";
                    }
                    if (delta_now > stoll(post_1)) {
                        delta_now -= stoll(post_1);
                        if (now_1 != now_2) {
                            counter += stoll(post_1);
                        }
                    } else if (delta_now < stoll(post_1)) {
                        if (now_1 != now_2) {
                            counter += stoll(post_1);
                        }
                        post_1.clear();
                        while(k1 < first_RLE.size() - 1){
                            now_2 = second_RLE[k2];
                            k1++;
                            while (isdigit(first_RLE[k1])) {
                                post_1 += first_RLE.substr(k1, 1);
                                k1++;
                            }
                            if (post_1.empty()) {
                                post_1 = "1";
                            }
                            counter += stoll(post_1);
                            post_1.clear();
                        }

                    } else {
                        if (now_1 != now_2) {
                            counter += delta_now;
                        }
                        delta_now = 0;
                        post_1.clear();
                        while(k1 < first_RLE.size() - 1){
                            now_2 = second_RLE[k2];
                            k1++;
                            while (isdigit(first_RLE[k1])) {
                                post_1 += first_RLE.substr(k1, 1);
                                k1++;
                            }
                            if (post_1.empty()) {
                                post_1 = "1";
                            }
                            counter += stoll(post_1);
                            post_1.clear();
                        }
                    }
                    post_1.clear();
                }
                break;
            }
            // Общий случай
            now_1 = first_RLE[k1];
            k1++;
            while(isdigit(first_RLE[k1])){
                post_1 += first_RLE.substr(k1, 1);
                k1++;
            }
            if (post_1.empty()){
                post_1 = "1";
            }

            if (delta_now > stoll(post_1)){
                delta_now -= stoll(post_1);
                if (now_1 != now_2){
                    counter += stoll(post_1);
                }
            }
            else if(delta_now < stoll(post_1)){
                if (now_1 != now_2){
                    counter += delta_now;
                }
                delta_now = stoll(post_1) - delta_now;
                perfect = 1;
            }
            else{
                if (now_1 != now_2){
                    counter += delta_now;
                }
                delta_now = 0;
                perfect = 0;
            }
            post_1.clear();
        }
        // Строки одинаково ушли
        else {
            if (k2 >= second_RLE.size() && k1 < first_RLE.size()) {
                while (k1 < first_RLE.size()) {
                    now_1 = first_RLE[k1];
                    k1++;
                    while (isdigit(first_RLE[k1])) {
                        post_1 += first_RLE.substr(k1, 1);
                        k1++;
                    }
                    if (post_1.empty()) {
                        post_1 = "1";
                    }
                    if (now_1 != now_2) {
                        counter += stoll(post_1);
                    }
                    post_1.clear();
                }
                break;
            } else if (k1 >= first_RLE.size() && k2 < second_RLE.size()) {
                while (k2 < second_RLE.size()) {
                    now_2 = second_RLE[k2];
                    k2++;
                    while (isdigit(second_RLE[k2])) {
                        post_2 += second_RLE.substr(k2, 1);
                        k2++;
                    }
                    if (post_2.empty()) {
                        post_2 = "1";
                    }
                    if (now_1 != now_2) {
                        counter += stoll(post_2);
                    }
                    post_2.clear();
                }
                break;
            } else if (k1 >= first_RLE.size() && k2 >= second_RLE.size()) {
                break;
            } else {
                now_1 = first_RLE[k1];
                k1++;
                now_2 = first_RLE[k2];
                k2++;
                //cout << first_RLE[k1] << " " <<  second_RLE[k2] << "\n";
                while (isdigit(first_RLE[k1])) {
                    post_1 += first_RLE.substr(k1, 1);
                    k1++;
                }
                if (post_1.empty()) {
                    post_1 = "1";
                }
                while (isdigit(second_RLE[k2])) {
                    post_2 += second_RLE.substr(k2, 1);
                    k2++;
                }
                if (post_2.empty()) {
                    post_2 = "1";
                }

                if (stoll(post_1) > stoll(post_2)) {
                    delta_now = stoll(post_1) - stoll(post_2);
                    perfect = 1;
                    if (now_1 != now_2){
                        counter += stoll(post_2);
                    }
                }
                if (stoll(post_1) < stoll(post_2)) {
                    delta_now = stoll(post_2) - stoll(post_1);
                    perfect = 2;
                    if (now_1 != now_2){
                        counter += stoll(post_1);
                    }
                }
                if (stoll(post_1) == stoll(post_2)) {
                    delta_now = 0;
                    perfect = 0;
                    if (now_1 != now_2){
                        counter += stoll(post_1);
                    }
                }
                post_1.clear();
                post_2.clear();
            }
        }
    }
    if (counter < k){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
    //cout << counter << " " << k;
    return 0;
}
