#pragma once

typedef struct Vector3 {
	float x, y;
	Vector3 add(Vector3 v);
	Vector3 subtraction(Vector3 v);
	float distance(Vector3 v);
}Vector3;