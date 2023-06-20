; ModuleID = 'minibasic'
source_filename = "minibasic"

@vars = internal global [26 x i32] zeroinitializer
@xe = external global i32

declare void @writeInteger(i32)

declare void @puti(i32)

define void @hello() {
entry:
  store i32 5, i32* @xe
  %0 = load i32, i32* @xe
  call void @writeInteger(i32 %0)
  ret void
}
