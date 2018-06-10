#include <cmath>
#include "RBset.h"

const double EPS(1e-5);

RBset::RBset(const RBset &t) : key(t.key), color(t.color), left(t.left), right(t.right), parent(t.parent) {
	if (left) {
		left = new RBset(*t.left);
		left->parent = this;
	}
	if (right) {
		right = new RBset(*t.right);
		right->parent = this;
	}
} 

RBset::~RBset() {
	if (parent)
		(this == parent->left ? parent->left : parent->right) = NULL;
	if (left)
		left->parent = parent;
	if (right)
		right->parent = parent;
}

pset RBset::grandparent() {
	if (parent)
		return parent->parent;
	return NULL;
}

pset RBset::uncle() {
	pset t(grandparent());
	if (!t)
		return NULL;
	if (parent == t->left)
		return t->right;
	return t->left;
}

pset RBset::sibling() {
	if (this == parent->left)
		return parent->right;
	else
		return parent->left;
}

pset RBset::rotate_left() {
	pset pivot(right);
	pivot->parent = parent;
	if (parent) {
		if (parent->left == this)
			parent->left = pivot;
		else
			parent->right = pivot;
	}
	right = pivot->left;
	if (right)
		right->parent = this;
	parent = pivot;
	pivot->left = this;
	return pivot;
}

pset RBset::rotate_right() {
	pset pivot(left);
	pivot->parent = parent;
	if (parent) {
		if (parent->left == this)
			parent->left = pivot;
		else
			parent->right = pivot;
	}
	left = pivot->right;
	if (left)
		left->parent = this;
	parent = pivot;
	pivot->right = this;
	return pivot;
}

pset RBset::insert(double k) {
	pset res(this);
	while (res)
		if (k < res->key)
			if (res->left)
				res = res->left;
			else
				break;
		else
			if (res->right)
				res = res->right;
			else
				break;
	if (k < res->key) {
		res->left = new RBset(k);
		res->left->parent = res;
		res = res->left->insert1();
	} else {
		res->right = new RBset(k);
		res->right->parent = res;
		res = res->right->insert1();
	}
	while (res->parent)
		res = res->parent;
	res->color = false;
	return res;
}

pset RBset::insert1() {
	if (!parent)
		color = false;
	else
		if (parent->color)
			return insert2();
	return this;
}

pset RBset::insert2() {
	pset u(uncle()), g(grandparent()), t(this);
	if (u && u->color) {
		parent->color = u->color = false;
		g = grandparent();
		g->color = true;
		return g->insert1();
	} else {
		if ((t == parent->right) && (parent == g->left))
			parent->rotate_left(), t = t->left;
		else if ((t == parent->left) && (parent == g->right))
			parent->rotate_right(), t = t->right;
		return t->insert3();
	}
}

pset RBset::insert3() {
	pset g(grandparent());
	parent->color = false;
	g->color = true;
	if ((this == parent->left) && (parent == g->left))
		return g->rotate_right();
	else
		return g->rotate_left();
}

pset RBset::erase(double k) {
	pset t(this), c, res(this);
	t = t->check(k);
	if (t->left && t->right) {
		for (c = t->left; c->right; c = c->right);
		t->key = c->key;
		t = c;
	}
	if (t->color) {
		if (!t->parent)
			res = NULL;
		delete t;
	} else {
		c = t->left ? t->left : t->right;
		if (c) {
			c->color = false;
			if (t->parent)
				(t->parent->left == t ? t->parent->left : t->parent->right) = c;
			else
				res = c;
			c->parent = t->parent;
		} else {
			if (!t->parent) {
				delete t;
				return NULL;
			}
			res = t->erase1();
			if (res) {
				while (res->parent)
					res = res->parent;
				res->color = false;
			}
			delete t;
		}
	}
	return res;
}

pset RBset::erase1() {
	pset s;
	if (parent) {
		s = sibling();
		if (s->color) {
			parent->color = true, s->color = false;
			if (this == parent->left)
				parent->rotate_left();
			else
				parent->rotate_right();
		}
		s = sibling();
		if (!parent->color && !s->color && (!s->left || !s->left->color) && (!s->right || !s->right->color)) {
			s->color = true;
			return parent->erase1();
		} else {
			if (parent->color && !s->color && (!s->left || !s->left->color) && (!s->right || !s->right->color))
				s->color = true, parent->color = false;
			else {
				if (!s->color)
					if (this == parent->left && (!s->right || !s->right->color) && s->left->color) {
						s->color = true, s->left->color = false;
						s->rotate_right();
					} else
						if (this == parent->right && (!s->left || !s->left->color) && s->right->color) {
							s->color = true, s->right->color = false;
							s->rotate_left();
						}
				s = sibling();
				s->color = parent->color;
				parent->color = false;
				if (this == parent->left) {
					s->right->color = false;
					parent->rotate_left();
				} else {
					s->left->color = false;
					parent->rotate_right();
				}
			}
		}
		return this;
	} else
		return left ? left : right;
}

pset RBset::check(double k) {
	pset res(this);
	while (res && std::abs(k - res->key) > EPS)
		if (k < res->key)
			res = res->left;
		else
			res = res->right;
	return res;
}