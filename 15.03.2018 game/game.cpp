// game.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<cstdio>
#include <cstdlib>
#include<ctime>
#include <string>
#include <vector>
#include<iostream>

using namespace std;

class unit
{
protected:
	float hp, dmg;	
	unit(float _hp, float _dmg) :hp(_hp), dmg(_dmg) {}
public:
	unit() {}
	virtual void take_dmg(float) = 0;
	virtual float get_dmg() = 0;
	virtual bool print_stats(const string) = 0;
};

class strength :public unit
{
protected:
	float armor;
	strength(float _hp, float _dmg, float _armor) :unit(_hp, _dmg), armor(_armor) {}
};

class tank :public strength
{
private:
	float dmg_reduce;
	float block_chance;
	bool block(float block_hance)
	{
		return rand() % 100<block_chance;
	}	
public:
	tank(float _hp, float _dmg, float _armor, float _dmg_rd, float _bc) :strength(_hp, _dmg, _armor), dmg_reduce(_dmg_rd), block_chance(_bc) {}
	float get_dmg()
	{
		return dmg;
	}
	void take_dmg(float dmg)
	{
		if (block(block_chance))
		{
			puts("Block!");
			hp -= dmg*dmg_reduce*armor * 0, 5;
		}
		else
			hp -= dmg*dmg_reduce*armor;
	}
	bool print_stats(const string name)
	{		
		printf("Tank %s: HP: %.2lf ", name, hp);
		return hp>0;
	}
};

class warior :public strength
{
private:
	float rage = 0;
	float rage_rate;	
public:
	warior(float _hp, float _dmg, float _armor, float _rr) :strength(_hp, _dmg, _armor), rage_rate(_rr) {}
	float get_dmg()
	{
		rage += rage_rate;
		return dmg + rage;
	}
	void take_dmg(float dmg)
	{
		hp -= dmg*armor;
	}
	bool print_stats(const string name)
	{
		printf("Warior %s: HP: %.2lf ", name, hp);
		return hp>0;
	}
};

class agility :public unit
{
protected:
	float agile;
	agility(float _hp, float _dmg, float _agile) :unit(_hp, _dmg), agile(_agile) {}
};

class thief :public agility
{
private:
	float crit_chance;
	bool crit(float crit_chance)
	{
		return rand() % 100<crit_chance;
	}	
public:
	thief(float _hp, float _dmg, float _agile, float _cc) :agility(_hp, _dmg, _agile), crit_chance(_cc) {}
	float get_dmg()
	{
		if (crit(crit_chance))
		{
			puts("Crit!");
			return dmg*agile * 5;
		}
		else
			return dmg*agile;
	}
	void take_dmg(float dmg)
	{
		hp -= dmg;
	}
	bool print_stats(const string name)
	{
		printf("Thief %s: HP: %.2lf ", name, hp);
		return hp>0;
	}
};
class ranger :public agility
{
private:
	float evasion_chance;
	bool evasion(float evasion_chance)
	{
		return rand() % 100<evasion_chance;
	}	
public:
	ranger(float _hp, float _dmg, float _agile, float _ec) :agility(_hp, _dmg, _agile), evasion_chance(_ec) {}
	float get_dmg()
	{
		return dmg*agile;
	}
	void take_dmg(float dmg)
	{
		if (evasion(evasion_chance))
		{
			puts("Evasion!");
		}
		else
			hp -= dmg;
	}
	bool print_stats(const string name)
	{
		printf("Ranger %s: HP: %.2lf ", name, hp);
		return hp>0;
	}
};

class inteligence :public unit
{
protected:
	float mana;
	void regen_mana() 
	{
		mana += 5;
	}	
public:
	inteligence(float _hp, float _dmg, float _mana) :unit(_hp, _dmg), mana(_mana) {}
	void take_dmg(float damage) {
		hp -= damage;
		regen_mana();
	}
};

class firemage :public inteligence
{
protected:
	float fireball() {
		if (mana >= 25) {
			mana -= 25;
			return 120;
		}
		else {
			puts("Not enought mana!");
			return 0;
		}
	}
public:
	firemage(float _hp, float _bd, float _m) : inteligence(_hp, _bd, _m) {}
	bool print_stats(const string name) {
		printf("Fire mage %s HP: %.2lf, mana: %d\n", name, hp, mana);
		return hp > 0;
	}
	float get_dmg() {
		puts("[1]\tSpell fireball\n[other]\tnothing");
		int c;
		scanf_s("%d", &c);
		switch (c) {
		case 1:
			return dmg + fireball();
		default:
			return dmg;
		}
	}
};

class frostmage :public inteligence
{
private:
	float lifesteal() {
		if (mana >= 10) {
			mana -= 10;
			return 1.1;
		}
		else
			return 1;
	}
public:
	frostmage(float _hp, float _bd, float _m) : inteligence(_hp, _bd, _m) {}
	bool print_stats(const string name) {
		printf("Arcane mage %s HP: %.2lf, mana: %d\n", name, hp, mana);
		return hp > 0;
	}
	float get_dmg() {
		hp += lifesteal();
		return dmg;
	}
};

int main() {
	srand(time(NULL));
	puts("Enter number of players");
	int n;
	scanf_s("%d", &n);
	vector<unit> player;
	//player.resize(2);
	//player.reserve(sizeof(unit));
	vector<string> name;
	string buffer = "";	
	bool *alive=new bool[n];
	int c;
	puts("Available classes:\n1\tThief\n2\tRanger\n3\tTank\n4\tWarior\n5\tFire mage\n6\tFrost mage");
	for (int i(0); i < n; ++i) {
		printf("Player #%d: [CLASS_ID] [NAME]\n", i + 1);		
		getline(cin, buffer);
		name.push_back(buffer);		
		alive[i] = true;
		scanf_s("%d", &c);
		switch (c) {
		case 1:
			player[i] = thief(250, 15, 2.5, 30);
			break;
		case 2:
			player[i] = ranger(250, 15, 3, 15);
			break;
		case 3:
			player[i] = tank(400, 20, 6, 20, 0.5);
			break;
		case 4:
			player[i] = warior(500, 20, 0.5, 0);
			break;
		case 5:
			player[i] = firemage(200, 15, 60);
			break;
		case 6:
			player[i] = frostmage(200, 20, 40);
		}
		player[i].print_stats(name[i]);
	}
	int target;
	for (int k(0);; k = (k + 1) % n) {
		if (!alive[k])
			continue;
		printf("Move player #%d\nWhom are attacking?\n", k + 1);
		scanf_s("%d", &target);
		player[target - 1].take_dmg(player[k].get_dmg());
		if (!player[target - 1].print_stats(name[target - 1]))
			printf("Player #%d is death\n", target), alive[target - 1] = false;
		player[k].print_stats(name[k]);
		puts("------------------------------");
	}
	return 0;
}

