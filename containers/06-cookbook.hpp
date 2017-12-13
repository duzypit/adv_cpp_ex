#ifndef COOKBOOK_HPP_QBXUGV7S
#define COOKBOOK_HPP_QBXUGV7S
#include <string>
#include <unordered_map>
#include <list>
#include <vector>

namespace cooking {

//typedef double title;
typedef std::string Title;

//typedef double string;
//typedef float recipeList;

//typedef float keywords;
typedef std::vector<std::string> keywords;
typedef double cost_t;

struct Ingredient {
    std::string name;
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

typedef std::list<Recipe> recipeList;

struct Cookbook {
    void addRecipe(Recipe, keywords = keywords{}){

    }
    //! Fast O(logN) lookup - MAP!
    recipeList findByKeywords(keywords){
        recipeList tmp;
        return tmp;
    }

    //! Search all recipes that can be created with a given recipes
    recipeList search(ingredients_t ingreds){
        recipeList tmp;
        return tmp;
    }

    //! fast O(logN) lookup - MAP!
    recipeList findRecipes(Title){
        recipeList tmp;
        return tmp;
    }

    std::map _data;
};

}  // namespace cooking

#endif /* end of include guard: COOKBOOK_HPP_QBXUGV7S */

