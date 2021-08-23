/// Switch Displacement in mm
pub struct SwitchDisplacement {
    _actuation: f32,
    _bottom_out: f32,
}

impl SwitchDisplacement {
    pub const fn new(actuation: f32, bottom_out: f32) -> SwitchDisplacement {
        SwitchDisplacement {
            _actuation: actuation,
            _bottom_out: bottom_out,
        }
    }

    pub const fn actuation(&self) -> f32 {
        self._actuation
    }

    pub const fn bottom_out(&self) -> f32 {
        self._bottom_out
    }
}

pub const CHERRY_MX: SwitchDisplacement = SwitchDisplacement::new(2.0, 4.0);
pub const CHERRY_MX_SPEED: SwitchDisplacement = SwitchDisplacement::new(1.2, 3.4);
pub const GATERON_INK_YELLOW: SwitchDisplacement = SwitchDisplacement::new(1.5, 3.5);
pub const KAILH_SPEED: SwitchDisplacement = SwitchDisplacement::new(1.1, 3.5);
