use std::cmp::min;

struct Solution {}

impl Solution {
    pub fn minimized_maximum(n: i32, quantities: Vec<i32>) -> i32 {
        let mut lo = 1;
        let mut high = *quantities.iter().max().unwrap();

        let mut result = high;

        while lo <= high {
            let mid = (lo + high) / 2;

            let chunks = Solution::count_chunks(mid, &quantities);

            if chunks <= n {
                result = min(result, mid);
                high = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        result
    }

    fn count_chunks(chunk_size: i32, quantities: &Vec<i32>) -> i32 {
        quantities
            .iter()
            .map(|quantity| Solution::ceil_div(*quantity, chunk_size))
            .sum()
    }

    fn ceil_div(num: i32, den: i32) -> i32 {
        (num / den) + if num % den == 0 { 0 } else { 1 }
    }
}

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn one() {
        let result = Solution::minimized_maximum(6, vec![11, 6]);

        assert_eq!(result, 3);
    }

    #[test]
    fn two() {
        let result = Solution::minimized_maximum(7, vec![15, 10, 10]);

        assert_eq!(result, 5);
    }

    #[test]
    fn three() {
        let result = Solution::minimized_maximum(1, vec![10000]);

        assert_eq!(result, 10000);
    }

    #[test]
    fn four() {
        let result = Solution::minimized_maximum(
            26,
            vec![
                24, 18, 12, 6, 3, 24, 5, 19, 10, 20, 2, 18, 27, 3, 13, 22, 11, 16, 19, 13,
            ],
        );

        assert_eq!(result, 19);
    }

    #[test]
    fn ceil_div() {
        assert_eq!(2, Solution::ceil_div(5, 3));
    }
}
