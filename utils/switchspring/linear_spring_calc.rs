mod switchspring {

    /// Linear Spring Calculator
    ///
    /// l  = spring length
    /// li = case length
    /// xa = actuation displacement
    /// xb = bottom out displacement
    /// fa = actuation force
    /// fb = bottom out force
    /// fi = initial force (usually compressiong from housing)
    /// k  = spring tension (for linear it's constant and not affect calc)
    ///
    /// Further refinement, if you only want to find l (spring length)
    /// you don't need the first equation, so don't need to involve fi
    ///
    /// fi = k(l-li)
    /// fa = k(l-(li-xa))
    /// fb = k(l-(li-xb))
    #[derive(Default, Debug)]
    pub struct LinearSpringCalc {
        actuation_displacement: f32,      // l
        bottom_out_displacement: f32,     // li
        case_length: f32,                 // xa
        spring_length: Option<f32>,       // xb
        actuation_force: Option<f32>,     // fa
        bottom_out_force: Option<f32>,    // fb
        initial_force: Option<f32>,       // fi
    }
}
