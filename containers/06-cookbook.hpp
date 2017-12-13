#ifndef COOKBOOK_HPP_QBXUGV7S
#define COOKBOOK_HPP_QBXUGV7S
#include <string>
#include <unordered_map>

namespace cooking {

//typedef double title;
typedef std::string Title;

typedef double string;
typedef float recipeList;

typedef float keywords;
typedef double cost_t;

struct Ingredient {
    string name;
    double quantity;
};

//typedef float ingredients_t;
typedef std::unordered_map<std::string, std::string> ingredients_t;

struct Recipe {
    Recipe(const char* t) : title(t){};
    Title title;
    ingredients_t ingreds;
    cost_t cost() const{
        cost_t tmp = 0;
        for(auto& v : ingreds){
            tmp += std::stod(v.second);
        }
        return tmp;
    }

};

struct Cookbook {
    void addRecipe(Recipe, keywords = keywords{});
    //! Fast O(logN) lookup
    recipeList findByKeywords(keywords);

    //! Search all recipes that can be created with a given recipes
    recipeList search(ingredients_t ingreds);

    //! fast O(logN) lookup
    recipeList findRecipes(Title);
};

}  // namespace cooking

#endif /* end of include guard: COOKBOOK_HPP_QBXUGV7S */

