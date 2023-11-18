#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void testCase();
vector<pair<double,double>> readTestCasePoints(int num_points);
int findMaximum(const vector<pair<double,double>> points, double bowl_diameter);
int checkTwoPoints(const vector<pair<double,double>> points, double bowl_diameter, int point_a_index, int point_b_index);
int countPointsInCircle(const vector<pair<double,double>> points, double bowl_diameter, pair<double,double> bowl_origin);
double distance(pair<double,double> point_a, pair<double,double> point_b);

int main() {
	int tests;
	cin >> tests;
	for(int test = 0; test < tests; test++) {
		testCase();
	}
	
	cout << flush;
}

void testCase() {
	int num_points;
	double bowl_diameter;
	cin >> num_points >> bowl_diameter;
	
	vector<pair<double,double>> points = readTestCasePoints(num_points);
	
	int solution = findMaximum(points, bowl_diameter);
	
	cout << solution << "\n";
}

vector<pair<double,double>> readTestCasePoints(int num_points) {
	vector<pair<double,double>> points;
	for(int index = 0; index < num_points; index++) {
		double x, y;
		cin >> x >> y;
		points.push_back({x,y});
	}
	return points;
}

int findMaximum(const vector<pair<double,double>> points, double bowl_diameter) {
	int maximum_so_far = 0;
	
	for(int point_a_index = 0; point_a_index < points.size(); point_a_index++) {
		for(int point_b_index = point_a_index + 1; point_b_index < points.size(); point_b_index++) {
			int score = checkTwoPoints(points, bowl_diameter, point_a_index, point_b_index);
			maximum_so_far = max(score, maximum_so_far);
		}
	}
	
	return maximum_so_far;
}

int checkTwoPoints(const vector<pair<double,double>> points, double bowl_diameter, int point_a_index, int point_b_index) {
	pair<double,double> point_a = points[point_a_index];
	pair<double,double> point_b = points[point_b_index];
	double a_b_distance = distance(point_a, point_b);
	
	if(a_b_distance > bowl_diameter) return 1;
	
	double half_distance = a_b_distance / 2.0;
	double half_x_distance = (point_b.first - point_a.first) / 2.0;
	double half_y_distance = (point_b.second - point_a.second) / 2.0;
	pair<double,double> midpoint = {point_a.first + half_x_distance,
									point_a.second + half_y_distance};
	double bowl_radius = bowl_diameter / 2.0;
	double midpoint_center_distance = sqrt((bowl_radius * bowl_radius) -
										   (half_distance * half_distance));
	double circle_center_x_distance = (midpoint_center_distance * half_y_distance) / half_distance;
	double circle_center_y_distance = (midpoint_center_distance * half_x_distance) / half_distance;
	
	pair<double,double> circle_center_a = {0.0,0.0};
	pair<double,double> circle_center_b = {0.0,0.0};
	
	circle_center_a.first = midpoint.first + circle_center_x_distance;
	circle_center_a.second = midpoint.second - circle_center_y_distance;
	circle_center_b.first = midpoint.first - circle_center_x_distance;
	circle_center_b.second = midpoint.second + circle_center_y_distance;
	
	int circle_a_count = countPointsInCircle(points, bowl_diameter, circle_center_a);
	int circle_b_count = countPointsInCircle(points, bowl_diameter, circle_center_b);
	
	int maximum_of_both = max(circle_a_count, circle_b_count);
	
	return maximum_of_both;
}

int countPointsInCircle(const vector<pair<double,double>> points, double bowl_diameter, pair<double,double> bowl_origin) {
	double bowl_radius = bowl_diameter / 2;
	int count = 0;
	for(pair<double,double> point : points) {
		if(distance(bowl_origin, point) <= bowl_radius)
			count++;
	}
	
	return count;
}

double distance(pair<double,double> point_a, pair<double,double> point_b) {
	double x_distance = fabs(point_a.first - point_b.first);
	double y_distance = fabs(point_a.second - point_b.second);
	double distance = sqrt((x_distance * x_distance) + (y_distance * y_distance));
	return distance;
}