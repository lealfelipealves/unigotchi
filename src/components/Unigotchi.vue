<template>
  <div class="hello">

    <div class='case'>
      <div class='title'>UNIGOTCHI</div>

      <div class='screen'>
        <div class="avatar"></div>
        <div class="status life">
          <ul>
            <li></li>
            <li></li>
            <li></li>
            <li></li>
            <li></li>
          </ul>
        </div>
        <div class="status eat">
          <ul>
            <li></li>
            <li></li>
            <li></li>
            <li></li>
            <li></li>
          </ul></div>
        <div class="status fun">
          <ul>
            <li></li>
            <li></li>
            <li></li>
            <li></li>
            <li></li>
          </ul></div>
        <div class="status sleep">
          <ul>
            <li></li>
            <li></li>
            <li></li>
            <li></li>
            <li></li>
          </ul></div>
      </div>

      <div class='list-buttons'>
        <button type="button" @click="addFun()">Fun</button>
        <button type="button" class="wrap-1" @click="addSleep()">Sleep</button>
        <button type="button" @click="addEat()">Eat</button>
        <!--<button type="button">Decide</button>
        <button type="button">Cancel</button>-->
      </div>
    </div>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  name: 'HelloWorld',
  props: {
    msg: String,
  },
  data() {
    return {
      fun: 0,
      sleep: 0,
      eat: 0,
    };
  },

  mounted() {
    this.fetchUsers();
  },

  methods: {
    fetchUsers() {
      const baseURI = 'https://jsonplaceholder.typicode.com/users';
      this.$http.get(baseURI)
        .then((result) => {
          this.users = result.data;
          console.log(this.users);
        });
    },

    addFun() {
      this.fun = this.fun + 1;
      console.log('fun', this.fun);
    },
    addEat() {
      this.eat = this.eat + 1;
      console.log('eat', this.eat);
    },
    addSleep() {
      this.sleep = this.sleep + 1;
      console.log('sleep', this.sleep);
    },
  },
  created() {
    axios.get('http://127.0.0.1:1880/receber')
      .then((response) => {
        console.log(response);
        // JSON responses are automatically parsed.
        this.posts = response.data;
      })
      .catch((e) => {
        this.errors.push(e);
      });
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
  position: relative;
  width: 240px;
  height: 240px;
  /*background: #a9e4f2;
  border-radius: 10%;
  box-shadow: inset -2px 2px 0 #0076a4;*/

  .avatar {
    position: absolute;
    width: 240px;
    height: 240px;
    background: url('../assets/unigotchi_desgin-07.svg');
    background-size: cover;

  }

  .fun {
    position: absolute;
    top:0;
    right:0;
    background: url('../assets/unigotchi_desgin-14.svg');
  }

  .eat {
    position: absolute;
    bottom:0;
    right:0;
    background: url('../assets/unigotchi_desgin-12.svg');
  }

  .sleep {
    position: absolute;
    bottom:0;
    left:0;
    background: url('../assets/unigotchi_desgin-13.svg');
  }

  .life {
    position: absolute;
    top:0;
    left:0;
    background: url('../assets/unigotchi_desgin-11.svg');
  }

  .status {

    ul {
      display: flex;
      flex-wrap: nowrap;
      list-style: none;
      padding: 0;
      margin: 0;

      li {
        width: 18px;
        height: 15px;
        background-repeat: no-repeat;
        background-size: cover;
      }

    }
  }


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
