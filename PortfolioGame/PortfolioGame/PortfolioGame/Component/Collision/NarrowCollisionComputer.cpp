#include "NarrowCollisionComputer.h"
#include <cfloat>
#include <algorithm>
#include <array>
#include "../../Constant/ConstantValue.h"
#include "../../Utility/Vec3.h"
#include "../../Utility/Quaternion.h"

//線分と線分の衝突判定
bool NarrowCollisionComputer::CheackCollisionRayAndRay(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Ray || collider_02_.shape != ColliderShapeTag::Ray)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//未実装

	//衝突していない
	return false;
}

//球と球の衝突判定
bool NarrowCollisionComputer::CheackCollisionSphereAndSphere(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Sphere || collider_02_.shape != ColliderShapeTag::Sphere)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//距離の2乗
	float distance_sq = (collider_02_.position - collider_01_.position).LengthSq();

	//半径の合計の2乗
	float total_radius_sq = (collider_01_.radius + collider_02_.radius) * (collider_01_.radius + collider_02_.radius);

	//衝突判定
	if (distance_sq <= total_radius_sq)
	{
		//衝突している
		return true;
	}

	//衝突していない
	return false;
}

//OBBとOBBの衝突判定
bool NarrowCollisionComputer::CheackCollisionOBBAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Box || collider_02_.shape != ColliderShapeTag::Box)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//分離軸定理を用いた衝突判定
	return SATOBBCollision(collider_01_, collider_02_);
}

//線分と球の衝突判定
bool NarrowCollisionComputer::CheackCollisionRayAndSphere(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Ray || collider_02_.shape != ColliderShapeTag::Sphere)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//線分のベクトル
	Vec3 ray = collider_01_.end - collider_01_.start;

	//線分の長さの2乗
	float ray_length_sq = ray.LengthSq();

	//線分の長さがほぼ0なら衝突不可で判定終了
	if (ray_length_sq <= FLT_EPSILON)
	{
		return false;
	}

	//線分の直線上へ線分の始点から球の中心点へのベクトルを投影したながさ
	float projection_ray_start_to_closest_on_sphere = Vec3Math::Dot(collider_02_.position - collider_01_.start, ray);

	//投影した長さの線分の長さへの割合
	float projection_rate = projection_ray_start_to_closest_on_sphere / ray.LengthSq();

	//線分内に収める
	projection_rate = std::clamp(projection_rate, 0.0f, 1.0f);

	//線分上の球の中心点への最接近点
	Vec3 closest_position = collider_01_.start + projection_rate * ray;

	//線分上の球の中心点への最接近点と球の中心点の距離の2乗
	float distance_sq_closest_on_sphere_and_sphere = (closest_position - collider_02_.position).LengthSq();

	//線分上の最接近点が球内もしくは球表面上なら衝突している
	if (distance_sq_closest_on_sphere_and_sphere <= collider_02_.radius * collider_02_.radius)
	{
		return true;
	}

	//衝突していない
	return false;
}

//線分とOBBの衝突判定
bool NarrowCollisionComputer::CheackCollisionRayAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Ray || collider_02_.shape != ColliderShapeTag::Box)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//スラブ法を用いた衝突判定
	return SlabCollision(collider_01_, collider_02_);
}

//球とOBBの衝突判定
bool NarrowCollisionComputer::CheackCollisionSphereAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Sphere || collider_02_.shape != ColliderShapeTag::Box)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//OBBのローカル座標系の基底軸(0:x, 1:y, 2:z)
	std::array<Vec3, 3> obb_local_axes
	{
		QuaternionMath::QuaternionRotate(Vec3{1.0f, 0.0f, 0.0f}, collider_02_.rotate),
		QuaternionMath::QuaternionRotate(Vec3{0.0f, 1.0f, 0.0f}, collider_02_.rotate),
		QuaternionMath::QuaternionRotate(Vec3{0.0f, 0.0f, 1.0f}, collider_02_.rotate),
	};

	//OBB中心点から球の中心点までのベクトル
	Vec3 obb_position_to_sphere_position = collider_01_.position - collider_02_.position;

	//OBB中心点から球の中心点までのベクトルをOBBのローカル座標系に持っていく
	Vec3 obb_local_obb_position_to_sphere_position =
	{
		Vec3Math::Dot(obb_position_to_sphere_position, obb_local_axes[0]),
		Vec3Math::Dot(obb_position_to_sphere_position, obb_local_axes[1]),
		Vec3Math::Dot(obb_position_to_sphere_position, obb_local_axes[2]),
	};

	//各ローカル軸方向の長さをOBBのサイズでクランプすることでOBB上の球の中心点への最近点を求める
	Vec3 obb_closest_point_to_sphere = collider_02_.position 
										+ (obb_local_axes[0] * std::clamp(obb_local_obb_position_to_sphere_position.x, -collider_02_.half_scale.x, collider_02_.half_scale.x))
										+ (obb_local_axes[1] * std::clamp(obb_local_obb_position_to_sphere_position.y, -collider_02_.half_scale.y, collider_02_.half_scale.y))
										+ (obb_local_axes[2] * std::clamp(obb_local_obb_position_to_sphere_position.z, -collider_02_.half_scale.z, collider_02_.half_scale.z));

	//OBB上の最近点から球の中心までの距離の2乗
	float length_sq_obb_closest_point_to_sphere = (collider_01_.position - obb_closest_point_to_sphere).LengthSq();

	//球の半径と衝突判定
	if (length_sq_obb_closest_point_to_sphere <= collider_01_.radius * collider_01_.radius)
	{
		return true;
	}

	//衝突していない
	return false;
}

//スラブ法での線分とOBBの衝突判定
bool NarrowCollisionComputer::SlabCollision(const NarrowCollider& ray_, const NarrowCollider& box_)
{
	//OBBの回転四元数が単位四元数か確認して正規化
	Quaternion box_rotate = box_.rotate;
	if (std::fabs(box_rotate.LengthSq() - 1.0f) > EPSILON)
	{
		box_rotate = box_rotate.Normalized();
	}

	/***********************************************************************************
		以後計算のfor文による簡略化のためにVec3をstd::array<float, 3>の形で記述する
		[0] : x
		[1] : y
		[2] : z
		に対応している
	************************************************************************************/

	//OBBローカル軸空間での線分の始点と終点
	Vec3 vec3_obb_local_ray_start = QuaternionMath::QuaternionRotate(ray_.start - box_.position, box_rotate.Conjugate());
	std::array<float, 3> obb_local_ray_start =
	{
		vec3_obb_local_ray_start.x,
		vec3_obb_local_ray_start.y,
		vec3_obb_local_ray_start.z,
	};

	Vec3 vec3_obb_local_ray_end = QuaternionMath::QuaternionRotate(ray_.end - box_.position, box_rotate.Conjugate());
	std::array<float, 3> obb_local_ray_end =
	{
		vec3_obb_local_ray_end.x,
		vec3_obb_local_ray_end.y,
		vec3_obb_local_ray_end.z,
	};

	//OBBローカル空間における境界ボックスの最小頂点
	Vec3 vec3_obb_local_min_vertex = box_.half_scale.Negative();
	std::array<float, 3> obb_local_min_vertex =
	{
		vec3_obb_local_min_vertex.x,
		vec3_obb_local_min_vertex.y,
		vec3_obb_local_min_vertex.z,
	};

	//OBBローカル空間における境界ボックスの最大頂点
	Vec3 vec3_obb_local_max_vertex = box_.half_scale;
	std::array<float, 3> obb_local_max_vertex =
	{
		vec3_obb_local_max_vertex.x,
		vec3_obb_local_max_vertex.y,
		vec3_obb_local_max_vertex.z,
	};

	//線分の始点か終点が境界ボックスの内部なら衝突している
	//始点
	bool is_ray_start_inside_obb = true;
	for (int i = 0; i < 3; ++i)
	{
		if ((obb_local_ray_start[i] < obb_local_min_vertex[i]) || (obb_local_ray_start[i] > obb_local_max_vertex[i]))
		{
			is_ray_start_inside_obb = false;
			break;
		}
	}

	if (is_ray_start_inside_obb)
	{
		return true;
	}

	//終点
	bool is_ray_end_inside_obb = true;
	for (int i = 0; i < 3; ++i)
	{
		if ((obb_local_ray_end[i] < obb_local_min_vertex[i]) || (obb_local_ray_end[i] > obb_local_max_vertex[i]))
		{
			is_ray_end_inside_obb = false;
			break;
		}
	}

	if (is_ray_end_inside_obb)
	{
		return true;
	}

	//線分がいずれかの軸方向で境界ボックスの外側に完全に存在する場合は分離している
	for (int i = 0; i < 3; ++i)
	{
		if (((obb_local_ray_start[i] < obb_local_min_vertex[i]) && (obb_local_ray_end[i] < obb_local_min_vertex[i])) ||
			((obb_local_ray_start[i] > obb_local_max_vertex[i]) && (obb_local_ray_end[i] > obb_local_max_vertex[i]))
			)
		{
			return false;
		}
	}

	//OBBローカル軸空間での線分ベクトル
	Vec3 vec3_obb_local_ray = vec3_obb_local_ray_end - vec3_obb_local_ray_start;
	std::array<float, 3> obb_local_ray_buffer =
	{
		vec3_obb_local_ray.x,
		vec3_obb_local_ray.y,
		vec3_obb_local_ray.z,
	};

	//割り算用OBBローカル軸空間での線分ベクトルの各成分の逆数を計算
	Vec3 vec3_invers_obb_local_ray_element = Vec3::Zero();
	std::array<float, 3> invers_obb_local_ray_element =
	{
		vec3_invers_obb_local_ray_element.x,
		vec3_invers_obb_local_ray_element.y,
		vec3_invers_obb_local_ray_element.z,
	};

	for (int i = 0; i < 3; ++i)
	{
		if (std::fabs(obb_local_ray_buffer[i]) > EPSILON)
		{
			invers_obb_local_ray_element[i] = 1.0f / obb_local_ray_buffer[i];
		}
		else
		{
			if ((obb_local_ray_start[i] < obb_local_min_vertex[i]) || (obb_local_ray_start[i] > obb_local_max_vertex[i]))
			{
				return false;
			}
		}
	}
	
	//OBBローカル軸空間の線分の始点から境界ボックススラブの最小点へのベクトル
	Vec3 vec3_obb_local_ray_start_to_obb_slab_min = vec3_obb_local_min_vertex - vec3_obb_local_ray_start;
	std::array<float, 3> obb_local_ray_start_to_obb_slab_min =
	{
		vec3_obb_local_ray_start_to_obb_slab_min.x,
		vec3_obb_local_ray_start_to_obb_slab_min.y,
		vec3_obb_local_ray_start_to_obb_slab_min.z,
	};

	//OBBローカル軸空間の線分の始点から境界ボックススラブの最大点へのベクトル
	Vec3 vec3_obb_local_ray_start_to_obb_slab_max = vec3_obb_local_max_vertex - vec3_obb_local_ray_start;
	std::array<float, 3> obb_local_ray_start_to_obb_slab_max =
	{
		vec3_obb_local_ray_start_to_obb_slab_max.x,
		vec3_obb_local_ray_start_to_obb_slab_max.y,
		vec3_obb_local_ray_start_to_obb_slab_max.z,
	};

	//スラブへの最遅到達時間
	float obb_slab_late_near_time = -FLT_MAX;

	//スラブからの最速逸脱時間
	float obb_slab_fast_far_time = FLT_MAX;

	//各ローカル軸の境界ボックスのスラブ到達時間と逸脱時間を計算して最遅到達時間と最速逸脱時間を計算
	for (int i = 0; i < 3; ++i)
	{
		if (std::fabs(obb_local_ray_buffer[i]) > EPSILON)
		{
			float time_01 = obb_local_ray_start_to_obb_slab_min[i] * invers_obb_local_ray_element[i];
			float time_02 = obb_local_ray_start_to_obb_slab_max[i] * invers_obb_local_ray_element[i];

			obb_slab_late_near_time = max(obb_slab_late_near_time, min(time_01, time_02));
			obb_slab_fast_far_time = min (obb_slab_fast_far_time, max(time_01, time_02));
		}
	}

	//衝突判定
	if (obb_slab_late_near_time > obb_slab_fast_far_time)
	{
		return false;
	}

	//線分の終点は境界ボックスに衝突する前に途切れているため衝突しない
	if (obb_slab_late_near_time > 1.0f)
	{
		return false;
	}

	//境界ボックスは始点から終点方向と逆方向にあるため衝突しない
	if (obb_slab_fast_far_time < 0.0f)
	{
		return false;
	}

	return true;
}

//分離軸定理でのOBBの衝突判定
bool NarrowCollisionComputer::SATOBBCollision(const NarrowCollider& box_01_, const NarrowCollider& box_02_)
{
	//Box_01のローカル軸
	std::array<Vec3, 3> box_01_axes =
	{
		QuaternionMath::QuaternionRotate(Vec3{1.0f, 0.0f, 0.0f}, box_01_.rotate),
		QuaternionMath::QuaternionRotate(Vec3{0.0f, 1.0f, 0.0f}, box_01_.rotate),
		QuaternionMath::QuaternionRotate(Vec3{0.0f, 0.0f, 1.0f}, box_01_.rotate),
	};

	//Box_02のローカル軸
	std::array<Vec3, 3> box_02_axes =
	{
		QuaternionMath::QuaternionRotate(Vec3{1.0f, 0.0f, 0.0f}, box_02_.rotate),
		QuaternionMath::QuaternionRotate(Vec3{0.0f, 1.0f, 0.0f}, box_02_.rotate),
		QuaternionMath::QuaternionRotate(Vec3{0.0f, 0.0f, 1.0f}, box_02_.rotate),
	};

	//Box_01のローカル軸上でSAT
	for (auto& Axis : box_01_axes)
	{
		//分離軸を見つけたら衝突していない
		if (FindSATAxis(Axis, box_01_, box_02_, box_01_axes, box_02_axes))
		{
			return false;
		}
	}

	//Box_02のローカル軸上でSAT
	for (auto& Axis : box_02_axes)
	{
		//分離軸を見つけたら衝突していない
		if (FindSATAxis(Axis, box_01_, box_02_, box_01_axes, box_02_axes))
		{
			return false;
		}
	}

	//外積軸上でのSAT
	for (auto& Box_01_Axis : box_01_axes)
	{
		for (auto& Box_02_Axis : box_02_axes)
		{
			//分離軸を見つけたら衝突していない
			if (FindSATAxis(Vec3Math::Cross(Box_01_Axis, Box_02_Axis), box_01_, box_02_, box_01_axes, box_02_axes))
			{
				return false;
			}
		}
	}

	//分離軸が見つからなかったので衝突している
	return true;
}

//分離軸探査
bool NarrowCollisionComputer::FindSATAxis(const Vec3& axis_, const NarrowCollider& box_01_, const NarrowCollider& box_02_, const std::array<Vec3, 3>& box_01_axes_, const std::array<Vec3, 3>& box_02_axes_)
{
	//軸が0ベクトルなら分離軸は発見不可
	if (axis_.LengthSq() < EPSILON)
	{
		return false;
	}

	//判定軸方向への中心間ベクトルの射影距離
	float obb_distance = std::fabs(Vec3Math::Dot(box_02_.position - box_01_.position, axis_));

	//Box_01の判定軸方向の射影サイズ
	float box_01_chack_axis_radius = std::fabs(Vec3Math::Dot(box_01_axes_[0], axis_) * box_01_.half_scale.x)
									+ std::fabs(Vec3Math::Dot(box_01_axes_[1], axis_) * box_01_.half_scale.y)
									+ std::fabs(Vec3Math::Dot(box_01_axes_[2], axis_) * box_01_.half_scale.z);

	//Box_02の判定軸方向の射影サイズ
	float box_02_chack_axis_radius = std::fabs(Vec3Math::Dot(box_02_axes_[0], axis_) * box_02_.half_scale.x)
									+ std::fabs(Vec3Math::Dot(box_02_axes_[1], axis_) * box_02_.half_scale.y)
									+ std::fabs(Vec3Math::Dot(box_02_axes_[2], axis_) * box_02_.half_scale.z);

	//2OBB間の距離がそれぞれのサイズの合計より大きければ間に分離軸がある
	if (obb_distance > box_01_chack_axis_radius + box_02_chack_axis_radius)
	{
		return true;
	}

	return false;
}