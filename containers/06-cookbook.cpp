#include <gtest/gtest.h>

#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "06-cookbook.hpp"

using namespace cooking;

//http://slides.com/uczelnia_bt_kw/containers#/13/1
//
/*
excercise
Cookbook:

    data structure that holds a number of recipes
    recipe can be added/removed
    fast look-up by title and keywords! (one keyword)
    recipes sorted by sum of quantity of ingridients
    Recipe is versioned: recipes with same title are considered different versions of the same recipe
*/


//template <typename T>
cooking::cost_t cost(cooking::recipeList rl) {
    //sum of all costs in rl;
    cost_t tmpCosts = 0;
    for(auto& r : rl){
        tmpCosts += r.cost();
    }

    return tmpCosts;
}

TEST(Cookbook, add_recipe) {

    Cookbook cb;
    Recipe budyn { "Budyn "};
    budyn.ingreds = { {"mleko", "50" }, {"masło", "100"} };
    cb.addRecipe(budyn);
    ASSERT_EQ(cb.findRecipes("Budyn").size(), 1);
    EXPECT_EQ(cost(cb.findRecipes("Budyn")), 150 );

}

TEST(Cookbook, different_version_of_recipe) {
    /*
      Cookbook cb;
      Recipe budyn { "Budyn "};
      budyn.ingreds = { {"mleko", "50" }, {"masło", "100"} };
      cb.addRecipe(budyn);
      budyn.ingreds.push_back( {"czekolada", "100"} );
      cb.addRecipe(budyn, {"czekolada"});
      EXPECT_EQ(cb.findRecipe("budyn").size(), 2);
      EXPECT_EQ(cb.findByKeywords("czekolada").size(), 1);
       */
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
