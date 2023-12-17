#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>

using namespace std;

class FoodRatings {
public:
    unordered_map<string, set<pair<int,string>>> cuisineRatings;
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodToCuisine;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            cuisineRatings[cuisines[i]].insert({-ratings[i], foods[i]});
            foodRating[foods[i]] = ratings[i];
            foodToCuisine[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &cuisine = foodToCuisine[food];
        int oldRating = foodRating[food];
        cuisineRatings[cuisine].erase({-oldRating,food});
        cuisineRatings[cuisine].insert({-newRating, food});
        foodRating[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return (*cuisineRatings[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */


int main() {
    // Sample data
    vector<string> foods = {"Pizza", "Sushi", "Burger", "Pasta", "Tacos"};
    vector<string> cuisines = {"Italian", "Japanese", "American", "Italian", "Mexican"};
    vector<int> ratings = {5, 4, 3, 4, 5};

    // Instantiate FoodRatings object
    FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);

    // Print the initial highest-rated food for each cuisine
    for (const string& cuisine : cuisines) {
        cout << "Highest rated food in " << cuisine << ": " << obj->highestRated(cuisine) << endl;
    }

    // Change the rating of a food
    string foodToChange = "Burger";
    int newRating = 4;
    obj->changeRating(foodToChange, newRating);

    // Print the highest-rated food for the cuisine after changing the rating
    string cuisineToCheck = "American";
    cout << "Highest rated food in " << cuisineToCheck << " after rating change: " << obj->highestRated(cuisineToCheck) << endl;

    // Clean up memory
    delete obj;

    return 0;
}
