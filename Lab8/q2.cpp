#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant {
public:
    string name;
    int hp;
    int atk;
    Combatant(){}
    Combatant(string n,int h,int a) {
        name=n; hp=h; atk=a;
    }
};

class CNode {
public:
    Combatant c;
    string key;
    CNode* left;
    CNode* right;
    CNode(Combatant cc) {
        c = cc;
        key = cc.name;
        left = right = NULL;
    }
};

class CombatBST {
public:
    CNode* root;
    CombatBST() { root = NULL; }

    CNode* insert(CNode* r, Combatant cc) {
        if(!r) return new CNode(cc);
        if(cc.name < r->key) r->left = insert(r->left,cc);
        else r->right = insert(r->right,cc);
        return r;
    }
    void insert(Combatant c) { root = insert(root,c); }

    CNode* findMin(CNode* r) {
        while(r && r->left) r = r->left;
        return r;
    }

    CNode* remove(CNode* r, string key) {
        if(!r) return NULL;
        if(key < r->key) r->left = remove(r->left,key);
        else if(key > r->key) r->right = remove(r->right,key);
        else {
            if(!r->left && !r->right) return NULL;
            else if(!r->left) return r->right;
            else if(!r->right) return r->left;
            CNode* m = findMin(r->right);
            r->c = m->c;
            r->key = m->key;
            r->right = remove(r->right,m->key);
        }
        return r;
    }
    void remove(string k) { root = remove(root,k); }

    CNode* frontline() { return findMin(root); }

    void inorder(CNode* r) {
        if(!r) return;
        inorder(r->left);
        cout<<r->c.name<<"("<<r->c.hp<<") ";
        inorder(r->right);
    }
    void print() { inorder(root); cout<<endl; }
};

int roll() { return rand()%5; }

void battleRound(CombatBST& h, CombatBST& e, int round) {
    cout<<"\nRound "<<round<<endl;

    cout<<"Heroes: "; h.print();
    cout<<"Enemies: "; e.print();

    CNode* hero = h.frontline();
    CNode* enemy = e.frontline();

    cout<<hero->c.name<<" attacks "<<enemy->c.name<<endl;
    int d = hero->c.atk + roll();
    enemy->c.hp -= d;
    cout<<"Damage "<<d<<" | "<<enemy->c.name<<" HP "<<enemy->c.hp<<endl;

    if(enemy->c.hp <= 0) {
        cout<<enemy->c.name<<" defeated"<<endl;
        e.remove(enemy->c.name);
        return;
    }

    cout<<enemy->c.name<<" attacks "<<hero->c.name<<endl;
    d = enemy->c.atk + roll();
    hero->c.hp -= d;
    cout<<"Damage "<<d<<" | "<<hero->c.name<<" HP "<<hero->c.hp<<endl;

    if(hero->c.hp <= 0) {
        cout<<hero->c.name<<" defeated"<<endl;
        h.remove(hero->c.name);
    }
}

int main() {
    srand(time(0));

    CombatBST heroes, enemies;

    heroes.insert(Combatant("Ares",30,6));
    heroes.insert(Combatant("Luna",25,7));
    heroes.insert(Combatant("Zed",28,5));
    heroes.insert(Combatant("Kai",35,4));
    heroes.insert(Combatant("Mira",22,8));

    enemies.insert(Combatant("Orc",30,5));
    enemies.insert(Combatant("Goblin",24,6));
    enemies.insert(Combatant("Shade",28,7));
    enemies.insert(Combatant("Drak",32,5));
    enemies.insert(Combatant("Ogre",40,4));

    int round = 1;
    while(heroes.root && enemies.root) {
        battleRound(heroes,enemies,round++);
    }

    if(heroes.root) cout<<"\nHeroes Win"<<endl;
    else cout<<"\nEnemies Win"<<endl;

    return 0;
}
