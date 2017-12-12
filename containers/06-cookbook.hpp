#ifndef COOKBOOK_HPP_QBXUGV7S
#define COOKBOOK_HPP_QBXUGV7S

namespace cooking {

typedef double title;
typedef double string;
typedef float recipeList;

typedef float keywords;
typedef double cost_t;

struct Ingredient {
    string name;
    double quantity;
};

typedef float ingredients_t;

struct Recipe {
    ingredients_t ingreds;
    cost_t cost() const;

};

struct Cookbook {
    void addRecipe(Recipe, keywords = keywords{});
    //! Fast O(logN) lookup
    recipeList findByKeywords(keywords);

    //! Search all recipes that can be created with a given recipes
    recipeList search(ingredients_t ingreds);

    //! fast O(logN) lookup
    recipeList findRecipes(title);
};

}  // namespace cooking

#endif /* end of include guard: COOKBOOK_HPP_QBXUGV7S */

