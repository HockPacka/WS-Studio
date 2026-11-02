//! Common radial mask: full opacity inside hardness radius; feather to outer radius.
pub fn influence(distance:f32,radius:f32,hardness:f32,falloff:f32)->f32 {
    if !distance.is_finite() || !radius.is_finite() || radius<=0.0 ||
       !hardness.is_finite() || !falloff.is_finite() {return 0.0;}
    let d=distance.max(0.0);
    if d>=radius{return 0.0;}
    let h=hardness.clamp(0.0,1.0);
    if d<=h*radius{return 1.0;}
    let t=((d/radius-h)/(1.0-h).max(f32::EPSILON)).clamp(0.0,1.0);
    let smoothed=1.0-t*t*(3.0-2.0*t);
    smoothed.powf(1.0+falloff.clamp(0.0,1.0)*4.0)
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn full_strength_within_inner_circle_zero_at_outer_circle(){
        for h in [0.0,0.3,0.6,1.0]{
            assert_eq!(influence(0.0,10.0,h,0.5),1.0);
            assert_eq!(influence(10.0*h,10.0,h,0.5),1.0);
            assert_eq!(influence(10.0,10.0,h,0.5),0.0);
        }
    }
    #[test]
    fn edge_is_smooth_and_falloff_changes_only_feather(){
        assert_eq!(influence(4.0,10.0,0.5,0.0),1.0);
        assert_eq!(influence(4.0,10.0,0.5,1.0),1.0);
        let low=influence(8.0,10.0,0.5,0.0);
        let high=influence(8.0,10.0,0.5,1.0);
        assert!(low>high && high>0.0);
        for d in 0..99 {assert!(influence(d as f32/10.0,10.0,0.5,0.5)
            >=influence((d+1) as f32/10.0,10.0,0.5,0.5));}
    }
    #[test]
    fn invalid_input_is_safe(){
        assert_eq!(influence(1.0,0.0,0.5,0.5),0.0);
        assert_eq!(influence(f32::NAN,10.0,0.5,0.5),0.0);
        assert_eq!(influence(5.0,10.0,f32::NAN,0.5),0.0);
        assert_eq!(influence(9.9,10.0,1.0,0.0),1.0);
    }
}
