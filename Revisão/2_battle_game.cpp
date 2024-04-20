#include <iostream>
#include <string>

// Classe base para representar criaturas no jogo
class Creature {
protected:
    std::string name; // Nome da criatura
    int health; // Saúde da criatura
    int damage; // Dano que a criatura pode causar

public:
    // Construtor
    Creature(const std::string& n, int h, int d) : name(n), health(h), damage(d) {}

    // Método virtual para atacar outra criatura
    virtual void attack(Creature& target) {
        std::cout << name << " ataca " << target.getName() << " causando " << damage << " de dano!" << std::endl;
        target.takeDamage(damage);
    }

    // Método para receber dano
    void takeDamage(int dmg) {
        health -= dmg;
        std::cout << name << " recebe " << dmg << " de dano!" << std::endl;
        if (health <= 0) {
            std::cout << name << " foi derrotado!" << std::endl;
        }
    }

    // Método para obter o nome da criatura
    std::string getName() const { return name; }

    // Método para acessar a saúde da criatura
    int getHealth() const { return health; }

    int getDamage() const { return damage;}

    void getStatus(){
        std::cout << "Name: " << name << ".\nHealth: " << health << ".\nDamage: " << damage << std::endl;
    }
};

// Classe para representar o jogador
class Player : public Creature {
private:
    int level; // Nível do jogador

public:
    // Construtor
    Player(const std::string& n, int h, int d, int l) : Creature(n, h, d), level(l) {}

    // Método para aumentar o nível do jogador
    void levelUp() {
        ++level;
        ++damage; // Aumenta o dano do jogador quando ele sobe de nível
        std::cout << name << " subiu de nível! Agora está no nível " << level << "!" << std::endl;
    }
};

// Classe para representar monstros
class Monster : public Creature {
public:
    // Construtor
    Monster(const std::string& n, int h, int d) : Creature(n, h, d) {}
};

int main() {
    Player player("Herói", 120, 50, 1);
    Monster monster("Dragão", 150, 30);

    std::cout << "Caracteristicas" << std::endl;
    player.getStatus();
    monster.getStatus();

    // Simulação de batalha
    std::cout << "Batalha começou!" << std::endl;
    while (player.getHealth() > 0 && monster.getHealth() > 0) {
        // Vez do jogador atacar
        player.attack(monster);
        if (monster.getHealth() <= 0) 
            break; // Se o monstro foi derrotado, sai do loop

        // Vez do monstro atacar
        monster.attack(player);
    }

    return 0;
}
