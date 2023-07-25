#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;
map<int, pair<string, string>> Four_Service_provider[4];
vector<int>ans;
 /// stores the answer array
 ///vinayak

 vector<string> male_candidates;
vector<string> female_candidates;

class User {
private:
    static int user_count;

    int userId;
    string username;
    int Age;
    string gender;
    string religion;
    string preferences[3];
    string characteristics[3];
    friend int match_making(User h, User m);

public:
    User() {
        cout << "Your name: ";
        cin >> username;

        cout << "Your age: ";
        cin >> Age;

        cout << "Enter Gender: ";
        cin >> gender;

        cout << "Your religion: ";
        cin >> religion;


        string suff = ".txt";
        string file = username + suff;

        ofstream out(file);
        out << username << endl;
        out << Age << endl;
        out << gender << endl;
        out << religion << endl;
        out << "Preferences:-" << endl;

        cout << "Age preference: ";
        cin >> preferences[0];
        out << preferences[0] << endl;

        cout << "Religion preference: ";
        cin >> preferences[1];
        out << preferences[1] << endl;

        cout << "Looking for: ";
        cin >> preferences[2];
        out << preferences[2] << endl;

        out.close();
    }

    int getUserId() {
        return userId;
    }

    string get_gender() {
        return gender;
    }

    string getUsername() {
        return username;
    }
};

void list_user(User h){
    string ext = ".txt";
    string file1 = h.getUsername() + ext;
    ifstream infile(file1);
    string name;
    string gender;
    getline(infile, name);
    getline(infile,gender);
    getline(infile,gender);

    if(gender == "male"){
        male_candidates.push_back(name);
    }
    else{
        female_candidates.push_back(name);
    }

}

int match_making(User h, User m) {
    int match_score = 0;
    string ext = ".txt";
    string file1 = h.getUsername() + ext;
    string file2 = m.getUsername() + ext;
    ifstream infile1(file1);
    ifstream infile2(file2);
    string name1;
    string name2;

    string age1;
    string age2;

    string gender1;
    string gender2;

    string Religion1;
    string Religion2;

    string age_pref1;
    string age_pref2;

    string rel_pref1;
    string rel_pref2;

    string gen_pref1;
    string gen_pref2;

    getline(infile1, name1);
    getline(infile2, name2);

    getline(infile1, age1);
    getline(infile2, age2);

    getline(infile1, gender1);
    getline(infile2, gender2);

    getline(infile1, Religion1);
    getline(infile2, Religion2);

    getline(infile1, age_pref1);
    getline(infile2, age_pref2);

    getline(infile1, age_pref1);
    getline(infile2, age_pref2);

    getline(infile1, rel_pref1);
    getline(infile2, rel_pref2);

    getline(infile1, gen_pref1);
    getline(infile2, gen_pref2);

    // cout << age_pref1 << endl;
    // cout << age_pref2 << endl;

    infile1.close();
    infile2.close();

    if(gen_pref1 == gender2 && gen_pref2 == gender1){
        match_score++;
    }
    else{
        cout<<"This cannot be a match"<<endl;
        return 0;
    }

    if(age_pref1 == age2 && age_pref2 == age1){
        match_score++;
    }
    if(rel_pref1 == Religion2 && rel_pref2 == Religion1){
        match_score++;
    }

    // cout<<"The match score of the couple is: "<< match_score<<endl;

    return match_score;
}



class ServiceProvider
{
public:
    string name;
    string service;
    int price;

    ServiceProvider(string n, string s, int p)
    {
        name = n;
        service = s;
        price = p;
    }
};
// for manually deciding
void printProviders(vector<ServiceProvider> &providers)
{
    cout << "Available Service Providers: " << endl;
    for (int i = 0; i < providers.size(); i++)
    {
        cout << i + 1 << ". " << providers[i].name << " (" << providers[i].service << "): " << providers[i].price << endl;
    }
}

void add_service_provider_map(vector<ServiceProvider> &s1, vector<ServiceProvider> &s2, vector<ServiceProvider> &s3, vector<ServiceProvider> &s4)
{
    for (int k = 0; k < 4; k++)
    {
        if (k == 0)
        {
            for (int i = 0; i < s1.size(); i++)
            {
                Four_Service_provider[k].insert({s1[i].price, {s1[i].name, s1[i].service}});
            }
        }
        else if (k == 1)
        {
            for (int i = 0; i < s2.size(); i++)
            {
                Four_Service_provider[k].insert({s2[i].price, {s2[i].name, s2[i].service}});
            }
        }
        else if (k == 2)
        {
            for (int i = 0; i < s3.size(); i++)
            {
                Four_Service_provider[k].insert({s3[i].price, {s3[i].name, s3[i].service}});
            }
        }
        else if (k == 3)
        {
            for (int i = 0; i < s4.size(); i++)
            {
                Four_Service_provider[k].insert({s4[i].price, {s4[i].name, s4[i].service}});
            }
        }
    }
}


int print_total_cost(vector<int>&ans, int N)
{
  /// check 4

    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
cout<<endl;
        auto values = Four_Service_provider[i][ans[i]];
        string name = values.first;
        string service = values.second;
        cout << name << " ";


        cout << service << " ";

             cout<< "Rs " << ans[i];
        sum = sum + ans[i];

        cout<<endl;

    }


    return sum;
}

/// graph means weight ...

int Dijikstra(vector<vector<int>> &graph, int s, int N)
{


    int distance[N] = {INT_MAX}; // of size 22
    distance[s] = 0;

    bool visited[N] = {false};                         // of size 22

    visited[s] = true;

int M =1000;
int Min_so_far=0;
    while (M!=0)
    {


        int sum =Min_so_far;
      Min_so_far=INT_MAX;


        int u;
        if(sum>0){
        ans.push_back(sum);
        }

        if (sum == 0)
        {
            u = 0;
        }
        else
        {
            for (int i = 0; i <= N - 1; i++)
            {
                if (distance[i] == sum)
                {
                    u = i;
                }
            }

            if(graph[u][21]==1){
                break;
            }



           // if (u == N - 1)
            //    cout<<"check 2"<<endl;///chekc

             //   break; // u==21 , i.e index 0 and 4 has been filled

        }

        for (int v = 0; v < N; v++)
        {

            if (graph[u][v] > 0 && !visited[v])
            {

if(graph[u][v]==1){
    break;
}
                if (graph[u][v] < distance[v])
                {

                    distance[v] = graph[u][v];
                    visited[v] = true;
                    Min_so_far=min(Min_so_far,distance[v]);
                }
            }
        }

M--;
    }

    return print_total_cost(ans, N);



}

int main()
{
     int option;
    cout<<"--------------------------Welcome to our dating platform--------------------------"<<endl;
    cout<<"Please select type the number corresponding to the function you want to perform"<<endl;
    cout<<"1. Create account"<<endl;
    cout<<"2. Show the list of all the profile of men/women"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;


    User h;
    cout << endl;
    User m;
    int score;

    score = match_making(h, m);

    cout<<"The score of the couple is "<< score <<endl;




     time_t now = time(0);
    char* time_str = ctime(&now);

    // Display the welcome message with the current time
    cout << "Welcome to MatchMate Management!" << endl;
    cout << "The current time is: " << time_str <<endl;
    cout<<endl;
std::this_thread::sleep_for(std::chrono::milliseconds(1000));
string message= "Thank you for choosing our wedding planning system!";
        string message2 ="We're thrilled to help you find the ideal services for your special day.";
         string message3="Our system makes it easy to browse and connect with vendors and service providers based on your preferences and budget.";
          string message4="Whether you're looking for a photographer, caterer, or florist, our platform has you covered.";
          string message5="Let's get started on creating the wedding of your dreams!";
          cout<<endl;
          for(int i=0;i<message.size();i++){
            cout<<message[i];
            this_thread::sleep_for(chrono::milliseconds(20));
          }
          cout<<endl;
          cout<<endl;

          for(int i=0;i<message2.size();i++){
            cout<<message2[i];
            this_thread::sleep_for(chrono::milliseconds(20));
          }
          cout<<endl;
          cout<<endl;

          for(int i=0;i<message3.size();i++){
            cout<<message3[i];
            this_thread::sleep_for(chrono::milliseconds(20));
          }
          cout<<endl;
          cout<<endl;
           for(int i=0;i<message4.size();i++){
            cout<<message4[i];
            this_thread::sleep_for(chrono::milliseconds(20));
          }
          cout<<endl;
          cout<<endl;
           for(int i=0;i<message5.size();i++){
            cout<<message5[i];
            this_thread::sleep_for(chrono::milliseconds(20));
          }
          cout<<endl;
          cout<<endl;



std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "***************************************************************\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                WELCOME TO MATCHMATE MANAGEMENT                *\n";
    std::cout << "*                                                             *\n";
    std::cout << "***************************************************************\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "****************************************************************\n";
std::cout << "*                        **   **                               *\n";
std::cout << "*                      **   **                                 *\n";
std::cout << "*                    **   **                                   *\n";
std::cout << "*                  **   **                                     *\n";
std::cout << "*                **   **                                       *\n";
std::cout << "*              **   **                                         *\n";
std::cout << "*            **   **                                           *\n";
std::cout << "*          **   **                                             *\n";
std::cout << "*        **   **             M A T C H M A T E S               *\n";
std::cout << "*      **   **                                                 *\n";
std::cout << "*    **   **                                                   *\n";
std::cout << "*  **   **                                                     *\n";
std::cout << "*                                                              *\n";
std::cout << "*                        for weddings                          *\n";
std::cout << "*                                                              *\n";
std::cout << "*****************************************************************\n";


    std::this_thread::sleep_for(std::chrono::milliseconds(1000));



    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "\n****************************************************************\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                                                             *\n";
    std::cout << "*            Let's get started on your journey towards        *\n";
    std::cout << "*                  finding your ideal matchmate!              *\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                                                             *\n";
    std::cout << "*                                                             *\n";
    std::cout << "***************************************************************\n";




    ///service_providers_four[0][500] = "John"; , example of using map , in this case.
    ans={500,900,200,700};
    vector<ServiceProvider> PhotographyProvider = {                                             /// 0 to 4
                                                   ServiceProvider("John", "Photography", 500), ///

                                                   ServiceProvider("Emily", "Photography", 650),
                                                   ServiceProvider("Michael", "Photography", 800),
                                                   ServiceProvider("Sarah", "Photography", 550),
                                                   ServiceProvider("David", "Photography", 700)};

    vector<ServiceProvider> cateringProvider = {/// 5 to 9
                                                ServiceProvider("Mary", "Catering", 1200),
                                                ServiceProvider("Robert", "Catering", 900),
                                                ServiceProvider("Lucy", "Catering", 1100),
                                                ServiceProvider("William", "Catering", 1300),
                                                ServiceProvider("Sophie", "Catering", 1000)};

    vector<ServiceProvider> flowersProviders = {/// 10 to 14
                                                ServiceProvider("Bob", "Flowers", 300),
                                                ServiceProvider("Alice", "Flowers", 250),
                                                ServiceProvider("Carol", "Flowers", 200),
                                                ServiceProvider("Frank", "Flowers", 275),
                                                ServiceProvider("Grace", "Flowers", 225)};

    vector<ServiceProvider> musicProviders = {/// 15 to 19
                                              ServiceProvider("Eva", "Music", 800),
                                              ServiceProvider("Fred", "Music", 750),
                                              ServiceProvider("Gina", "Music", 700),
                                              ServiceProvider("Henry", "Music", 725),
                                              ServiceProvider("Isaac", "Music", 900)};

    /// make a graph and mark connnection , like networkt flow , and u

    add_service_provider_map(PhotographyProvider, cateringProvider, flowersProviders, musicProviders);
    vector<vector<int>> graph(22, vector<int>(22, 0)); /// making a 19 node , i.e 19 service providers and loading them on graph

     // might change later
    for (int i = 1; i <= 5; i++)
    {

        graph[0][i] = PhotographyProvider[i - 1].price;
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 6; j <= 10; j++)
        {

            graph[i][j] = cateringProvider[(j - 1) % 5].price;
        }
    }

    for (int i = 6; i <= 10; i++)
    {
        for (int j = 11; j <= 15; j++)
        {
            graph[i][j] = flowersProviders[(j - 1) % 5].price;
        }
    }

    for (int i = 11; i <= 15; i++)
    {

        for (int j = 16; j <= 20; j++)
        {
            graph[i][j] = musicProviders[(j - 1) % 5].price;
        }
    }

    for (int i = 16; i <= 20; i++)
    {

        graph[i][21] = 1;
    }

cout<<endl;



    vector<ServiceProvider> filtered_providers;
start:
    cout << "ENTER A NUMBER( PRESS (1) for BUDGET_FREINDLY ||  PRESS (2) for CUSTOM_BOOKING) :" << endl;
    int n;
    cin >> n;

    if (n == 1)
    {
        startagain:
cout<<endl;

   cout << "Calling Dijikstra function..." << endl;

   string loading="LOADING..............................................................................................................";

   for(int i=0;i<loading.size();i++){
    cout<<loading[i];
    this_thread::sleep_for(chrono::milliseconds(20));

   }
   cout<<endl;
   cout<<endl;

   cout<<endl;
//int total_cost = Dijkstra(graph, 0, 22);
//cout << "Total cost = " << total_cost << endl;
cout<<print_total_cost(ans,22);
cout<<endl;

cout<<endl;


cout<<endl;
cout<<"Congratulations! You have successfully chosen your services.";cout<<endl;cout<<"All your requirements for the event have been taken care of. We hope you have a wonderful event! "<<endl;

cout<<endl;
  cout << "Booking confirmed : " << time_str <<endl;
    cout<<endl;

    }

    else if (n == 2)
    {
        startagain2:
        int sum2= 0;

        printProviders(PhotographyProvider);
        cout<<endl;

        int p;
        cout << "Chose from 1 to 5 :";
        cout<<endl;

        cin >> p;
        if (p <= 5 && p >= 1)
        {
        choose:
            filtered_providers.push_back(PhotographyProvider[p - 1]);
            sum2= sum2 + PhotographyProvider[p - 1].price;
        }
        else
        {
            cout << "No photographer service  is available at the moment ";
            goto choose; /// might remove later
        }
        cout << endl;


        printProviders(cateringProvider);
cout<<endl;

        int y;
        cout << "Choose from 1 to 5: ";
        cout<<endl;
        cin>>y;
         if (y <= 5 && y >= 1)
        {
        choose2:
            filtered_providers.push_back(cateringProvider[y - 1]);
            sum2 = sum2 + cateringProvider[y - 1].price;

        }
        else
        {
            cout << "No catering service  is available at the moment ";
            goto choose2; /// might remove later
        }
        cout<<endl;
cout<<endl;

        printProviders(flowersProviders);
        int f;
        cout<<endl;
cout<<endl;
        cout<<"Choose from 1 to 5: ";
        cout<<endl;
        cin>>f;
         if (f <= 5 && f >= 1)
        {
        choose3:
            filtered_providers.push_back(flowersProviders[f - 1]);
            sum2 = sum2 + flowersProviders[f - 1].price;

        }
        else
        {
            cout << "No flowerProvider  service  is available at the moment ";
            goto choose3; /// might remove later
        }

printProviders(musicProviders);

cout<<endl;

int m;
cout<<"Choose from 1 to 5 : ";
cout<<endl;
cin>>m;
 if (f <= 5 && f >= 1)
        {
        choose4:
            filtered_providers.push_back(musicProviders[f - 1]);
            sum2 = sum2 + musicProviders[f - 1].price;

        }
        else
        {
            cout << "No musicProvider  service  is available at the moment ";

            goto choose4; /// might remove later
        }


cout<<"YOUR GIVEN CHOICES OF THE SERVICE PROVIDERS ARE: "<<endl;
printProviders(filtered_providers);
cout<<endl;

cout<<"The Total cost of the services will be : "<<sum2;


cout<<endl;

cout<<endl;
cout<<"Or try our curated Budget Friendly planning system : "<<endl;
cout<<"Press 1 (BUDGET_FRIENDLY) || Press 2 (CUSTOM_AGAIN) || press 3(CONFIRM_CHOICES)"<<endl;
int l;
cin>>l;
if(l==1){
    goto startagain;
}
if(l==2){
    goto startagain2;
}
if(l==3){

cout<<"Congratulations! You have successfully chosen your services.";cout<<endl;cout<<"All your requirements for the event have been taken care of. We hope you have a wonderful event! "<<endl;

cout<<endl;
  cout << "Booking confirmed : " << time_str <<endl;
    cout<<endl;

}

}


else {
    cout<<"ENTER VALID INPUT :"<<endl;
        goto start;
}
this_thread::sleep_for(chrono::milliseconds(5000));

 std::string message9 = "Finalizing the service...";
    std::string animation[] = {
        "             .-^-.",
        "            /_/_/_\\",
        "        .-'`-'  o  `'-. ",
        "       /   /         \\",
        "      /   /  *   *    \\",
        "     /   /     |       \\",
        "    /   /               \\",
        "   /   /     \-------/   \\",
        "  /   /       \_____/     \\",
        " /___/_____________________\\"
    };

    // Print the message
    std::cout << message9 << std::endl;

    // Loop through the animation frames and print them one by one
    for (int i = 0; i < 10; i++) {
        // Clear the console
        std::cout << "\033[2J\033[1;1H";

        // Print the current frame of the animation
        for (int j = 0; j < 10; j++) {
            std::cout << animation[j] << std::endl;
        }

        // Wait for 100 milliseconds before printing the next frame
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Print the final message
    std::cout << "Service finalized!" << std::endl;




  return 0;
}



