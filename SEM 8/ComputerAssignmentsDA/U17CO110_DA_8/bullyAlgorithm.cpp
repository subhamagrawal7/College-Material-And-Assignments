#include<bits/stdc++.h>
using namespace std;

class Process{
    
    private:
        int p_id;
        int priority;
        bool is_active;

    public:
        Process(int p_id, int priority, bool is_active){
            this->p_id = p_id;
            this->priority = priority;
            this->is_active = is_active;
        }

        void changeStatus() {
            this->is_active = !(this->is_active);
        }
        
        void setPriority(int priority) {
            this->priority = priority;
        }

        int getPriority() {
            return this->priority;
        }

        bool getStatus() {
            return this->is_active;
        }

        int getID() {
            return this->p_id;
        }
        
};

void bullyElectionAlgorithm(vector< Process * > processes, int starting_process){

    queue< int > q;
    
    bool vis[processes.size()];
    memset(vis, false, sizeof vis);

    int leader = -1; 
    q.push(starting_process);

    cout << "\n********* Starting elections *********\n";
    while(!q.empty()){

        int p_id = q.front();
        q.pop();

        for(int i=0; i< processes.size(); i++){
            if(processes[i]->getPriority() > processes[p_id]->getPriority()){
                cout << "[+] Process " << p_id + 1 << " sending Election message to Process " << i+1 << endl; 
            }
        }

        bool hasRecieved = false;
        for(int i=0; i< processes.size(); i++){
            if(processes[i]->getPriority() > processes[p_id]->getPriority()){
                if(processes[i]->getStatus()){
                    cout << "[+] Recieved OK message from Process " << i+1 << endl; 
                    hasRecieved = true;
                    if(!vis[i]){
                        q.push(i);
                        vis[i] = true;
                    }
                }
            }
        }
        if(!hasRecieved) leader = p_id;
        cout << "\n";
    }

    for(int i=0; i< processes.size(); i++){
        if(processes[i]->getStatus() && i != leader){
            cout << "[+] Process " << leader + 1 << " sending message to " << i + 1 << " that " <<  " it is coordinator." << endl; 
        }
    }
}

int main(){

    cout << "********** BULLY ELECTION ALGORITHM SIMULATION **********\n";

    int num_of_processes, p_id, priority, status;
    bool is_active;
    set< int > priorities;

    // Creating all processes;
    cout << "[+] Enter the number of processes: ";
    cin >> num_of_processes;

    vector< Process * > processes;
    for(int i=0; i<num_of_processes; i++){
        cout << "\n[+] For process " << (i+1) << ":\n";
        
        // Taking priority
        cout << "[+] Enter priority: ";
        cin >> priority;
        while(true){
            if(priorities.find(priority) == priorities.end()) break;
            else {
                cout << "[+] Another process has same priority\n";
                cout << "[+] Enter priority: ";
                cin >> priority;
            }
        }
        
        status = -1;
        cout << "[+] Status of this process(1 for active, 0 for not active):";
        cin >> status;
        while(true){
            if(status == 0 || status == 1) break;
            else{
                cout << "[+] Status can only be 0 or 1\n";
                cout << "[+] Active status of this process(1 for active, 0 for not active):";
                cin >> status;
            }
        }
        is_active = (status == 1 ? true : false);
        processes.push_back(new Process(i, priority, is_active));
    }

    
    // Implementating
    int choice;
    bool isRunning = true;
    while(isRunning){
        
        cout << "\n\n[+] Choose any one of below:\n1. Change status of a process\n2. Change priority of process\n3. Start Election algorithm\n4. EXIT\n";
        cin >> choice;

        switch(choice){
            case 1 : cout << "[+] Enter process id: ";
                     cin >> p_id;
                     processes[p_id - 1]->changeStatus();
                     cout << processes[p_id - 1]->getStatus() << endl;
                     cout << "[+] Status changed successfully\n";
                     break;

            case 2 : cout << "[+] Enter process id: ";
                     cin >> p_id;
                     priorities.erase(processes[p_id - 1]->getPriority());
                     cout << "[+] Enter new priority: ";
                     cin >> priority;
                     while(true){
                        if(priorities.find(priority) == priorities.end()) break;
                        else {
                            cout << "[+] Another process has same priority\n";
                            cout << "[+] Enter priority: ";
                            cin >> priority;
                        }
                     }
                     processes[p_id - 1]->setPriority(priority);
                     cout << "[+] Priority changed successfully\n";
                     break;

            case 3 : cout << "Enter the process id to start election: ";
                     cin >> p_id;
                     while(true){
                         if(processes[p_id - 1]->getStatus() == false){
                             cout << "Chosen process not currently active\n";
                             cout << "Enter the process id to start election: ";
                             cin >> p_id;
                         }else break;
                     }
                     bullyElectionAlgorithm(processes, p_id - 1);
                     break;
            
            case 4 : isRunning = false;
                     break;

            default: cout << "[+] No such option\n";
                     break;
        }
        cout << "\n\n";
    }
}