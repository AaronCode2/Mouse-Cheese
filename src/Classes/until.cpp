#include "until.hpp"


static void GetRotatedRectPoints(Rectangle rect, float rotation, Vector2 out[4]) {
    Vector2 center = { rect.x + rect.width / 2.0f, rect.y + rect.height / 2.0f };
    float cosr = cosf(rotation * DEG2RAD);
    float sinr = sinf(rotation * DEG2RAD);

    Vector2 half = { rect.width / 2.0f, rect.height / 2.0f };


    out[0] = { center.x - half.x * cosr + half.y * sinr, center.y - half.x * sinr - half.y * cosr }; 
    out[1] = { center.x + half.x * cosr + half.y * sinr, center.y + half.x * sinr - half.y * cosr };
    out[2] = { center.x + half.x * cosr - half.y * sinr, center.y + half.x * sinr + half.y * cosr };
    out[3] = { center.x - half.x * cosr - half.y * sinr, center.y - half.x * sinr + half.y * cosr };
}


static void ProjectOntoAxis(Vector2 axis, const Vector2 points[4], float &min, float &max) {

    min = max = (points[0].x * axis.x + points[0].y * axis.y);

    for (int i = 1; i < 4; i++) {

        float proj = (points[i].x * axis.x + points[i].y * axis.y);
        
        if (proj < min) min = proj;
        if (proj > max) max = proj;
    }
}

bool CheckCollisionRecsRotated(Rectangle rect1, float rot1, Rectangle rect2, float rot2) {

    Vector2 r1[4], r2[4];

    GetRotatedRectPoints(rect1, rot1, r1);
    GetRotatedRectPoints(rect2, rot2, r2);

    Vector2 axes[4] = {

        { r1[1].x - r1[0].x, r1[1].y - r1[0].y },
        { r1[3].x - r1[0].x, r1[3].y - r1[0].y },
        { r2[1].x - r2[0].x, r2[1].y - r2[0].y },
        { r2[3].x - r2[0].x, r2[3].y - r2[0].y }
    };

    for (int i = 0; i < 4; i++) {

        float len = sqrtf(axes[i].x * axes[i].x + axes[i].y * axes[i].y);

        axes[i].x /= len;
        axes[i].y /= len;
    }

    for (int i = 0; i < 4; i++) {

        float min1, max1, min2, max2;

        ProjectOntoAxis(axes[i], r1, min1, max1);
        ProjectOntoAxis(axes[i], r2, min2, max2);

        if (max1 < min2 || max2 < min1)
            return false; 
    }

    return true;
}
