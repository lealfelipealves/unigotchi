<template>
  <div class="hello">

    <div class='case'>
      <div class='title'>UNIGOTCHI</div>

      <div class='screen'>
        <avatar :unigotch="unigotchi" />

        <div class="status life">
          <status tipo="life" :valor="unigotchi.vida.value" />
        </div>
        <div class="status eat">
          <status tipo="eat" :valor="unigotchi.fome.value" />
        </div>
        <div class="status fun">
          <status tipo="fun" :valor="unigotchi.diversao.value" />
        </div>
        <div class="status sleep">
          <status tipo="sleep" :valor="unigotchi.sono.value" />
        </div>
      </div>

      <div class='list-buttons'>
        <button type="button" title="Diversão" @click="addDiversao()">Diversão</button>
        <button type="button" title="Fome" class="wrap-1" @click="addFome()">Fome</button>
        <button type="button" title="Sono"  @click="addSono()">Sono</button>
      </div>
    </div>
  </div>
</template>

<script>
import Status from '@/components/Status.vue';
import Avatar from '@/components/Avatar.vue';

export default {
  name: 'HelloWorld',
  components: {
    Avatar,
    Status,
  },
  data() {
    return {
      unigotchi: {
        diversao: {
          value: 5,
        },
        fome: {
          value: 5,
        },
        sono: {
          value: 5,
        },
        vida: {
          value: 5,
        },
      },
    };
  },

  mounted() {
    this.ready();
    // this.apiLoadUnigotchi();
  },

  methods: {

    apiLoadUnigotchi() {
      this.$http.get(`${this.$baseURI}/status`)
        .then((result) => {
          this.unigotchi = result.data;
          console.log(this.unigotchi);
        });
    },

    ready() {
      this.apiLoadUnigotchi();

      setInterval(() => {
        this.apiLoadUnigotchi();
      }, 30000);
    },

    addDiversao() {
      if (this.unigotchi.diversao.value < 6) {
        this.unigotchi.diversao.value += 1;
        this.$http.post(`${this.$baseURI}/diversao`, { value: this.unigotchi.diversao.value })
          .then((result) => {
            this.unigotchi = result.data;
            console.log(this.unigotchi);
          });
      }
    },
    addFome() {
      if (this.unigotchi.fome.value < 6) {
        this.unigotchi.fome.value += 1;
        this.$http.post(`${this.$baseURI}/fome`, { value: this.unigotchi.fome.value })
          .then((result) => {
            this.unigotchi = result.data;
            console.log(this.unigotchi);
          });
      }
    },
    addSono() {
      if (this.unigotchi.sono.value < 6) {
        this.unigotchi.sono.value += 1;
        this.$http.post(`${this.$baseURI}/sono`, { value: this.unigotchi.sono.value })
          .then((result) => {
            this.unigotchi = result.data;
            console.log(this.unigotchi);
          });
      }
    },
  },
};
</script>

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
  color: #fff;
}

.screen {
  position: relative;
  width: 240px;
  height: 240px;
  /*background: #a9e4f2;
  border-radius: 10%;
  box-shadow: inset -2px 2px 0 #0076a4;*/

  .status {
    position: absolute;
  }

  .life {
    top:5px;
    left:5px;
  }

  .fun {
    top:5px;
    right:5px;
  }

  .sleep {
    bottom:7px;
    left:7px;
  }

  .eat {
    bottom:7px;
    right:7px;
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

</style>
