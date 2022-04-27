#include "pch.h"
#include <gtest/gtest.h>
#include "../SFML_Game_Cpts122PA9/Game.h"

//im just leaving this here as reference
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(PlayerTest, HealthStarts30)
{
	Player playerTest;
	EXPECT_EQ(30, playerTest.getHealthMax());
}

TEST(EnemyTest, PointsInit1)
{
	Enemy enemyTest;
	EXPECT_EQ(1, enemyTest.getPoints());
}

TEST(EnemyTest, DamageInitCorrectly)
{
	Enemy enemyTest;
	EXPECT_EQ(1, enemyTest.getDamage());
}

TEST(ProjectileTest, MovementSpeed)
{
	Projectile projectileTest;
	EXPECT_EQ(5.f, projectileTest.getMovementSpeed());	
}

TEST()
{
	Projectile2 projectileTest;
	EXPECT_EQ(5.f, projectileTest.getMovementSpeed());
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}