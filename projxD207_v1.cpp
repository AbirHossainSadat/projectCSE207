#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    string msg;
    string op1, op2, op3, op4;
    double point1, point2, point3, point4; 
    Node* next = nullptr;

    Node(string msg, string op1, string op2, string op3, string op4) {
        this->msg = msg;
        this->op1 = op1;
        this->op2 = op2;
        this->op3 = op3;
        this->op4 = op4;
        this->point1 = 2.5; this->point2 = 5.0; 
        this->point3 = 7.5; this->point4 = 10.0;
    }
};

class Tree {
public:
    double totalPoints = 0.0; 
    Node* root = nullptr; 

    void add(string q, string o1, string o2, string o3, string o4) {
        Node* newNode = new Node(q, o1, o2, o3, o4);
        if (!root) {
            root = newNode;
        } else {
            Node* cur = root;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
    }

    int getQuestionCount() {
        int c = 0; Node* cur = root;
        while(cur) { c++; cur = cur->next; }
        return c;
    }

    void ask() {
        Node* cur = root;
        while (cur) {
            cout << "\n[QUESTION] " << cur->msg << endl;
            cout << "1. " << cur->op1 << " | 2. " << cur->op2 << endl;
            cout << "3. " << cur->op3 << " | 4. " << cur->op4 << endl;
            int choice;
            cout << "Select (1-4): "; cin >> choice;
            
            if(choice == 1) totalPoints += cur->point1;
            else if(choice == 2) totalPoints += cur->point2;
            else if(choice == 3) totalPoints += cur->point3;
            else if(choice == 4) totalPoints += cur->point4;
            cur = cur->next;
        }
    }
};

int main() {
    // --- LEVEL 1: GENERAL INTENT ---
    Tree* L1 = new Tree();
    L1->add("What role are you targeting?", "QA/Support", "Web Dev", "Data Science", "AI/ML Engineer");
    L1->add("Target Monthly Salary (BDT)?", "30k-50k", "50k-80k", "80k-120k", "150k+");
    L1->add("Preferred Work Days?", "6 Days", "5 Days", "4 Days", "Remote/Flexible");
    L1->add("Daily Work Hours?", "12+ Hours", "10 Hours", "8 Hours", "6 Hours");
    L1->add("Company Type?", "Small Startup", "Local Agency", "MNC", "FAANG/Global");

    // --- LEVEL 2: BRANCHES ---
    Tree* n1 = new Tree(); // High Ambition Path
    n1->add("Years of Experience?", "Fresh Graduate", "1-2 Years", "3-5 Years", "5+ Years");
    n1->add("Specialized Certs?", "None", "Basic (Coursera)", "Professional (AWS/GCP)", "Expert/Research");
    n1->add("System Design Knowledge?", "None", "Heard of it", "Can design basics", "Expert level");
    n1->add("Leadership Experience?", "None", "Team Lead", "Project Manager", "Department Head");
    n1->add("Open Source Contrib?", "None", "Few PRs", "Active Contributor", "Maintainer");

    Tree* n2 = new Tree(); // Mid Path
    n2->add("Tech Stack Proficiency?", "Learning", "Can build with help", "Independent Dev", "Full Stack Expert");
    n2->add("Data Structures/Algo?", "Weak", "Basic", "Competitive Programmer", "Codeforces Candidate Master+");
    n2->add("University CGPA?", "Below 3.0", "3.0 - 3.5", "3.5 - 3.8", "3.8 - 4.0");
    n2->add("English Communication?", "Basic", "Conversational", "Professional", "Fluent/Native");
    n2->add("Framework Knowledge?", "1 Framework", "2 Frameworks", "Multi-stack", "System Architect");

    Tree* n3 = new Tree(); // Entry/Low Path
    n3->add("Personal Projects?", "None", "1-2 Simple", "3+ Hosted Projects", "Complex Full-scale apps");
    n3->add("Internship Done?", "No", "1 (Local)", "2+", "At a Reputed Firm");
    n3->add("GitHub Profile?", "Empty", "Few repos", "Clean & Documented", "Highly active green squares");
    n3->add("Problem Solving Skills?", "Struggling", "Can solve Easy", "Can solve Medium", "Consistent Solver");
    n3->add("Tool Knowledge (Git/Docker)?", "None", "Git only", "Git & Docker", "Full DevOps pipeline");

    // --- LEVEL 3: DEEPER PROBING (9 branches, 3 per L2 path) ---

    // --- From n1 (High Ambition) ---
    Tree* n1_high = new Tree(); // Elite Track
    n1_high->add("Can you design a system handling 1M+ requests/sec?", "No idea", "Conceptually yes", "Done it in interviews", "Built one in production");
    n1_high->add("How do you handle a production outage at 3 AM?", "Panic", "Follow runbook", "Debug & fix live", "Lead incident response");
    n1_high->add("Mentorship experience?", "Never mentored", "Helped juniors casually", "Formal 1-on-1 mentor", "Built mentorship programs");
    n1_high->add("How do you stay updated with cutting-edge tech?", "I don't actively", "Read blogs/news", "Build side projects with new tools", "Publish research/talks");
    n1_high->add("Salary negotiation confidence?", "I take whatever is offered", "I research market rates", "I negotiate with data", "I have competing offers strategy");

    Tree* n1_mid = new Tree(); // Strong Professional Track
    n1_mid->add("Largest team you've worked with?", "Solo only", "2-3 people", "5-10 people", "10+ cross-functional");
    n1_mid->add("How do you handle code reviews?", "Never done", "Accept all feedback", "Give & receive constructively", "Define review standards");
    n1_mid->add("Deployment experience?", "Never deployed", "Manual deploy", "CI/CD pipelines", "Full GitOps workflow");
    n1_mid->add("How do you approach debugging a feature you didn't write?", "Avoid it", "Read code slowly", "Use logs & breakpoints systematically", "Trace architecture & fix root cause");
    n1_mid->add("What's your testing philosophy?", "No tests", "Write when told", "TDD practitioner", "Full coverage + integration tests");

    Tree* n1_low = new Tree(); // Ambition-Reality Gap Track
    n1_low->add("Have you ever failed a technical interview?", "Never interviewed", "Yes, gave up after", "Yes, analyzed & improved", "Yes, now I coach others");
    n1_low->add("How many hours/week do you self-study?", "0-2 hours", "3-5 hours", "6-10 hours", "10+ focused hours");
    n1_low->add("Can you explain a complex concept to a non-tech person?", "Not really", "With difficulty", "Clearly with analogies", "I teach/write about it regularly");
    n1_low->add("What's your approach when stuck on a problem?", "Give up quickly", "Ask someone immediately", "Research & try 2-3 approaches", "Systematically exhaust all angles");
    n1_low->add("Portfolio website?", "No website", "Basic template", "Custom built & polished", "Has blog, projects & analytics");

    // --- From n2 (Mid Path) ---
    Tree* n2_high = new Tree(); // Mid-High: Upward Mobility Track
    n2_high->add("Have you contributed to any tech community?", "No", "Joined a Discord/forum", "Active in meetups/hackathons", "Organize events/run communities");
    n2_high->add("Can you write production-ready API documentation?", "Never tried", "Basic README", "Swagger/OpenAPI docs", "Full developer portal");
    n2_high->add("Database optimization skills?", "Only basic queries", "Know indexing", "Query optimization & profiling", "Designed schemas for scale");
    n2_high->add("How do you prioritize tasks under pressure?", "Work on whatever feels right", "Simple to-do list", "Eisenhower matrix/priority system", "Data-driven sprint planning");
    n2_high->add("Cross-team collaboration experience?", "Never", "Occasional meetings", "Regular cross-team projects", "Led cross-functional initiatives");

    Tree* n2_mid = new Tree(); // Mid-Mid: Steady Builder Track
    n2_mid->add("Have you ever refactored legacy code?", "Never", "Small tweaks", "Major module rewrite", "Full system migration");
    n2_mid->add("How comfortable are you with ambiguous requirements?", "Need everything spelled out", "Can ask clarifying questions", "Can propose solutions", "Thrive in ambiguity");
    n2_mid->add("Security awareness?", "What's SQL injection?", "Know common vulnerabilities", "Implement security best practices", "Conduct security reviews");
    n2_mid->add("How do you handle disagreements with a senior dev?", "Stay silent", "Agree reluctantly", "Present my reasoning respectfully", "Back arguments with data/benchmarks");
    n2_mid->add("Side projects outside coursework?", "None", "Started but abandoned", "1-2 completed", "Continuous side project habit");

    Tree* n2_low = new Tree(); // Mid-Low: Foundation Builder Track
    n2_low->add("Can you read and understand error messages?", "They confuse me", "Sometimes", "Usually figure it out", "I debug from stack traces quickly");
    n2_low->add("Version control habits?", "What's Git?", "Basic add/commit", "Branching & merging", "Git flow with rebasing");
    n2_low->add("How do you learn a new programming language?", "Avoid learning new ones", "Watch tutorials only", "Build a project with it", "Read docs + build + contribute");
    n2_low->add("Comfort with command line/terminal?", "Afraid of it", "Basic navigation", "Daily driver", "Write shell scripts & automate");
    n2_low->add("Networking with industry professionals?", "Zero connections", "LinkedIn only", "Attend events & follow up", "Have referrals at target companies");

    // --- From n3 (Entry/Low Path) ---
    Tree* n3_high = new Tree(); // Entry-High: Hidden Potential Track
    n3_high->add("What motivates you to enter tech?", "Just need a job", "Interested in tech generally", "Passionate about building things", "Want to solve real-world problems");
    n3_high->add("How do you handle constructive criticism?", "Take it personally", "Accept silently", "Reflect and improve", "Actively seek feedback");
    n3_high->add("Willingness to relocate for an opportunity?", "Absolutely not", "Maybe for a great role", "Yes, within the country", "Yes, internationally");
    n3_high->add("Can you work in a team under tight deadlines?", "I prefer solo work", "I can manage", "I perform well under pressure", "I lead teams under pressure");
    n3_high->add("Attitude toward unpaid internships?", "Never", "Only if prestigious", "Yes for learning", "Already doing one + freelancing");

    Tree* n3_mid = new Tree(); // Entry-Mid: Slow Starter Track
    n3_mid->add("How many programming languages do you know?", "None well", "1 language basics", "2 languages decently", "3+ with project experience");
    n3_mid->add("Have you ever completed an online course fully?", "Never finished one", "1 course", "3+ courses", "Built portfolio from courses");
    n3_mid->add("Typing speed (WPM)?", "Hunt and peck", "30-40 WPM", "50-70 WPM", "80+ WPM touch typist");
    n3_mid->add("Comfort presenting in front of others?", "Terrified", "Nervous but can do it", "Confident presenter", "Enjoy public speaking");
    n3_mid->add("Daily screen time on productive work?", "Under 1 hour", "1-3 hours", "4-6 hours", "8+ focused hours");

    Tree* n3_low = new Tree(); // Entry-Low: Wake-Up Call Track
    n3_low->add("Do you have a clear career goal for the next 2 years?", "No plan at all", "Vague idea", "Written goals", "Detailed roadmap with milestones");
    n3_low->add("How often do you code outside of class?", "Never", "Rarely", "Weekly", "Almost daily");
    n3_low->add("Do you understand what a job interview process looks like?", "No clue", "Heard about it", "Researched stages", "Practiced mock interviews");
    n3_low->add("How do you spend your free time?", "Social media/gaming only", "Mix of leisure & learning", "Mostly self-improvement", "Building skills + networking");
    n3_low->add("Are you willing to start with a lower position to grow?", "No, I want senior immediately", "Reluctantly", "Yes, I understand the process", "Yes, I have a growth plan already");

    // --- EXECUTION ---
    cout << "--- LEVEL 1: THE TARGET ---" << endl;
    L1->ask();

    // Route to L2 branch
    Tree* l2Path;
    double l1Score = L1->totalPoints;
    if (l1Score >= 40) l2Path = n1;
    else if (l1Score >= 25) l2Path = n2;
    else l2Path = n3;

    cout << "\n--- LEVEL 2: QUALIFICATIONS ---" << endl;
    l2Path->ask();

    // Route to L3 branch based on which L2 was taken and its score
    Tree* l3Path;
    double l2Score = l2Path->totalPoints;

    if (l2Path == n1) {
        if (l2Score >= 40) l3Path = n1_high;
        else if (l2Score >= 25) l3Path = n1_mid;
        else l3Path = n1_low;
    } else if (l2Path == n2) {
        if (l2Score >= 40) l3Path = n2_high;
        else if (l2Score >= 25) l3Path = n2_mid;
        else l3Path = n2_low;
    } else {
        if (l2Score >= 40) l3Path = n3_high;
        else if (l2Score >= 25) l3Path = n3_mid;
        else l3Path = n3_low;
    }

    cout << "\n--- LEVEL 3: DEEP DIVE ---" << endl;
    l3Path->ask();

    // --- FINAL RESULT CALCULATION ---
    double finalScore = l1Score + l2Score + l3Path->totalPoints;
    double maxPossible = 150.0; // 15 questions * 10 points max each
    double percentage = (finalScore / maxPossible) * 100;

    cout << "\n====================================" << endl;
    cout << "JOB READINESS REPORT" << endl;
    cout << "====================================" << endl;
    cout << "Level 1 Score: " << l1Score << " / 50" << endl;
    cout << "Level 2 Score: " << l2Score << " / 50" << endl;
    cout << "Level 3 Score: " << l3Path->totalPoints << " / 50" << endl;
    cout << "------------------------------------" << endl;
    cout << "Total Points: " << finalScore << " / " << maxPossible << endl;
    cout << "Probability of Landing this Job: " << percentage << "%" << endl;
    cout << "------------------------------------" << endl;
    
    if(percentage > 85) cout << "Status: ELITE CANDIDATE - You're ready to dominate the market!";
    else if(percentage > 70) cout << "Status: STRONG CONTENDER - High chance with focused prep.";
    else if(percentage > 50) cout << "Status: DEVELOPING - Good foundation, keep building skills.";
    else if(percentage > 30) cout << "Status: EARLY STAGE - Prioritize projects, skills & networking.";
    else cout << "Status: GROUND ZERO - Start with basics: learn, build, repeat.";
    cout << "\n====================================" << endl;

    delete L1; delete n1; delete n2; delete n3;
    delete n1_high; delete n1_mid; delete n1_low;
    delete n2_high; delete n2_mid; delete n2_low;
    delete n3_high; delete n3_mid; delete n3_low;
    return 0;
}