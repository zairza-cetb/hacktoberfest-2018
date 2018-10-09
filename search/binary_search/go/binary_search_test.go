package binarysearch

import "testing"

func Test_binarysearch(t *testing.T) {
	type args struct {
		elements []int
		target   int
	}
	tests := []struct {
		name    string
		args    args
		want    int
		wantErr bool
	}{
		{
			"empty",
			args{
				[]int{},
				2,
			},
			0,
			true,
		},
		{
			"simple 1",
			args{
				[]int{2},
				2,
			},
			0,
			false,
		},
		{
			"simple 2",
			args{
				[]int{0, 2, 4, 6, 8, 10, 12},
				2,
			},
			1,
			false,
		},
		{
			"negative",
			args{
				[]int{-4, -2, 0, 2, 4, 6, 8, 10, 12},
				2,
			},
			3,
			false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got, err := binarysearch(tt.args.elements, tt.args.target)
			if (err != nil) != tt.wantErr {
				t.Errorf("binarysearch() error = %v, wantErr %v", err, tt.wantErr)
				return
			}
			if got != tt.want {
				t.Errorf("binarysearch() = %v, want %v", got, tt.want)
			}
		})
	}
}
