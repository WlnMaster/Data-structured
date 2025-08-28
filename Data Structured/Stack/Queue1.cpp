#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Process {
    int pid, arrival, service;
    Process(int p, int a, int s) : pid(p), arrival(a), service(s) {}
};

// จัดเรียงตาม arrival time
bool compareArrival(const Process& a, const Process& b) {
    return a.arrival < b.arrival;
}

int main() {
    int n;
    cin >> n;
    vector<Process> input;

    for (int i = 0; i < n; ++i) {
        int pid, arrival, service;
        cin >> pid >> arrival >> service;
        input.push_back(Process(pid, arrival, service));
    }

    sort(input.begin(), input.end(), compareArrival); // เรียงตามเวลาเข้ามา
    stack<Process> lifoStack;
    int time = 0;
    int index = 0;

    while (index < n || !lifoStack.empty()) {
        // เพิ่ม process ที่เข้ามา ณ เวลานั้นลง stack
        while (index < n && input[index].arrival == time) {
            lifoStack.push(input[index]);
            index++;
        }

        if (!lifoStack.empty()) {
            Process current = lifoStack.top();
            lifoStack.pop();

            // รัน process นี้จนจบ (non-preemptive)
            while (current.service > 0) {
                cout << current.pid << " : " << current.service << endl;
                current.service--;
                time++;

                // ระหว่างนี้อาจมี process ใหม่เข้า ให้ push ลง stack
                while (index < n && input[index].arrival == time) {
                    lifoStack.push(input[index]);
                    index++;
                }
            }
        } else {
            // ไม่มี process ที่รันได้ รอเวลา
            time++;
        }
    }

    return 0;
}
