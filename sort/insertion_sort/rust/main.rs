pub fn insertion_sort<T>(values: &mut [T])
    where T: Ord
{
    for i in 0..values.len() {
        for j in (0..i).rev() {
            if values[j] >= values[j + 1] {
                values.swap(j, j + 1);
            } else {
                break;
            }
        }
    }
}

fn main() {
    let mut vals = [2, 1, 5, 3, 6, 4];
    insertion_sort(&mut vals);
    let expected: Vec<i32> = (1..7).collect();

    if vals.to_vec() != expected {
        println!("error! {:?} {:?}", vals, expected)
    }
    println!("worked as expected")
}
