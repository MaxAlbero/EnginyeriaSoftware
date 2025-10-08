//#include <iostream>
//#include <vector>
//
//class Figure {
//public:
//	virtual void Draw() {
//		std::cout << "I am a figure." << std::endl;
//	}
//};
//
//class Triangle : public Figure {
//public:
//	void Draw() override {
//		std::cout << "I am a Triangle." << std::endl;
//	}
//};
//
//class Square : public Figure {
//public:
//	void Draw() override {
//		std::cout << "I am a Square." << std::endl;
//	}
//};
//
//class Character {
//public:
//	Character(int hp): hp(hp){ } //hp(hp) es como hacer un this
//
//	int hp;
//	virtual void Attack(Character* target) = 0; //función abstracta
//	/*{
//		std::cout << "I am a character attacking" << std::endl;
//	}*/
//	virtual void Die() = 0;
//};
//
//class Hero : public Character {
//public:
//
//	Hero(int hp, int fame):
//		//Constructors to call before executing this constructor
//		fame(fame), Character(hp){ }
//
//	//Hero():
//	//	Character(10){ } //El constructor de hero puede simplemente 
//	//					//necesitar de forma obligatoria el constructor
//	//					//de character, que ya le puede dar un valor por defecto
//
//	int fame;
//	void Attack(Character* target) override {
//		Character::Attack(target); //Esto nos sirve para poder ejecutar la función del padre
//		//Ya que al hacer override, SIEMPRE sobreescribimos las funciones del padre con
//		//con las propias de los hijos
//		//std::cout << "I am a Hero attacking" << std::endl;
//	}
//
//	void Die() override {}
//};
//
//class Villain : public Character {
//public:
//
//	Villain(int hp) :
//		Character(hp) {
//	}
//
//	void Attack(Character* target) override {
//		Character::Attack(target);
//
//	}
//
//	void Die() override {}
//};
//
//
//int main() {
//	//Figure* fig = new Square;
//	//fig->Draw();
//
//	/*Figure* f = new Figure;
//	f->Draw();
//	Triangle* t = new Triangle;
//	t->Draw();
//	Square* s = new Square;
//	s->Draw();*/
//
//	/*std::vector<Figure*> figures;
//
//	figures.push_back(new Figure);
//	figures.push_back(new Triangle);
//	figures.push_back(new Square);
//
//	for (Figure* f : figures) {
//		f->Draw();
//	}*/
//
//	//Character* a = new Hero(10,10);
//	//Character* b = new Hero(20,30);
//	////Hero c;
//
//	//a->Attack(b);
//	//a->Attack(&c); //Hero c ES un character, pero no es un puntero, asi que hay que usar
//	// "&" para darle la dirección de la variable, ya que sino no le das su dirección
//
//	Hero b(10, 10);
//	b.Die();
//
//	Character* c = new Hero(1, 1);
//	c->Die();
//
//	std::vector<Character*> characters;
//
//	characters.push_back(new Hero(10, 10));
//	characters.push_back(new Villain(10));
//
//	for (Character* c : characters) {
//		if (Hero* temp = dynamic_cast<Hero*>(c)) {
//			std::cout << "I am a hero" << std::endl;
//			temp->fame = 10;
//		}
//		else if (Villain* temp = dynamic_cast<Villain*>(c)) {
//			std::cout << "I am a Villain" << std::endl;
//		}
//	}
//}