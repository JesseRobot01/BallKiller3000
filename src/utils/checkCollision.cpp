#include "../ball.h"
#include "../enemy.h"
#include "../player.h"
#include "../data.h"

bool Ball::hasCollision(Ball ballToCheck) {
    if (ballNumber == ballToCheck.ballNumber) return false;
    if (ballToCheck.isDead) return false;
    if (isDead) return false;
    return pos.CheckCollision(ballToCheck.pos, size - 5 + ballToCheck.size);
}

bool Ball::hasCollision(Enemy enemyToCheck) {
    if (enemyToCheck.isDead) return false;
    if (isDead) return false;
    return pos.CheckCollision(
            Rectangle(enemyToCheck.pos.x - size - 5, enemyToCheck.pos.y - size - 5, enemyToCheck.size.x + size + 5 * 2,
                      enemyToCheck.size.y + size + 5 * 2));
}

bool Ball::hasCollision(Player playerToCheck) {
    return playerToCheck.hasCollision(*this);
}

bool Ball::isInScreen(Vector2 posToCheck) {
    if (posToCheck.x >= size && posToCheck.x <= screenWidth - size) {
        if (posToCheck.y >= size && posToCheck.y <= screenHeight - size) {
            return true;
        }
    }
    return false;
}


bool Enemy::hasCollision(Ball ballToCheck) {
    return ballToCheck.hasCollision(*this);
}

bool Enemy::hasCollision(Enemy enemyToCheck) {
    if (enemyNumber == enemyToCheck.enemyNumber) return false;
    if (enemyToCheck.isDead) return false;
    if (isDead) return false;
    return CheckCollisionRecs(
            Rectangle(pos.x, pos.y, size.x, size.y),
            Rectangle(enemyToCheck.pos.x, enemyToCheck.pos.y, enemyToCheck.size.x, enemyToCheck.size.y)
    );
}

bool Enemy::hasCollision(Player playerToCheck) {
    return playerToCheck.hasCollision(*this);
}

bool Enemy::isInScreen(Vector2 posToCheck) {
    if (posToCheck.x > 0 && posToCheck.x + size.x < screenWidth) {
        if (posToCheck.y > 0 && posToCheck.y + size.y < screenHeight) {
            return true;
        }
    }
    return false;
}

bool Player::hasCollision(Ball ballToCheck) {
    if (ballToCheck.isDead) return false;
    return pos.CheckCollision(ballToCheck.pos, size - 5 + ballToCheck.size);
}

bool Player::hasCollision(Enemy enemyToCheck) {
    if (enemyToCheck.isDead) return false;
    return pos.CheckCollision(
            Rectangle(enemyToCheck.pos.x - size - 5, enemyToCheck.pos.y - size - 5, enemyToCheck.size.x + size + 5 * 2,
                      enemyToCheck.size.y + size + 5 * 2));
}

bool Player::hasCollision(Player playerToCheck) {
    if (playerNumber == playerToCheck.playerNumber) return false;
    return pos.CheckCollision(playerToCheck.pos, size - 5 + playerToCheck.size);
}

bool Player::isInScreen(Vector2 posToCheck) {
    if (posToCheck.x >= size && posToCheck.x <= screenWidth - size) {
        if (posToCheck.y >= size && posToCheck.y <= screenHeight - size) {
            return true;
        }
    }
    return false;
}


