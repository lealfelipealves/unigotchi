<template>
  <div class="hello">
    <div class='case'>
      <div class='title'>UNIGOTCHI</div>

      <div class='screen'>

      </div>

      <div class='list-buttons'>
        <button type="button">Status</button>
        <button type="button" class="wrap-1">Select</button>
        <button type="button">Reset</button>
        <!--<button type="button">Decide</button>
        <button type="button">Cancel</button>-->
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'HelloWorld',
  props: {
    msg: String,
  },
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang="scss">
@import url('https://fonts.googleapis.com/css?family=Bangers&display=swap');

.case {
  position: relative;
  box-sizing: border-box;
  width:424px;
  height: 525px;
  border-radius: 100%;
  background: url('../assets/case.svg');
  display:flex;
  justify-content: center;
  align-items: center;
  flex-wrap:wrap;
}
.title {
  position: absolute;
  top:75px;
  width:100%;
  font-family: 'Bangers', cursive;
  font-size: 45px;
  letter-spacing: 1px;
  text-shadow: 2px 2px 1px rgba(77, 9, 50, 0.75);
}
.screen {
  position: absolute;
  width: 240px;
  height: 240px;
  background: url('../assets/uni-6.svg');
  background-size: cover;
  /*background: #a9e4f2;
  border-radius: 10%;
  box-shadow: inset -2px 2px 0 #0076a4;*/
}

.list-buttons {
  position: absolute;
  bottom: 35px;
  width:100%;
}
button {
  border:0;
  width:45px;
  height:45px;
  background: #F2F742;
  box-sizing: border-box;
  box-shadow: inset -7px -7px 0 rgba(0,0,0,0.2);
  border-radius: 100%;
  font-size: 0px;
  margin-right:15px;

  &:hover {
    box-shadow: inset -7px -7px 0 rgba(0,0,0,0.35);
  }
}
.wrap-1 {
  padding-bottom: 25px !important;
}
.title {
  color: #fff;
}

</style>
