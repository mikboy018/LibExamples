#[no_mangle]
pub extern "C" fn rust_add(a: f64, b: f64) -> f64{
    a+b
}

#[no_mangle]
pub extern "C" fn rust_div(a: f64, b: f64) -> f64{
    let mut c = b;
    if c == 0.0 {
        c = 0.000000001
    }
    a/c
}

pub fn add(left: u64, right: u64) -> u64 {
    left + right
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
        let resut = rust_add(2.2, 3.3);
        assert_eq!(result, 5.5);
    }
}
